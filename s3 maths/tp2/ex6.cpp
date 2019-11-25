#include <iostream>
#include <eigen3/Eigen/Dense>
#include <ctime>
#include <cassert>

Eigen::VectorXd lu(const Eigen::MatrixXd &A, const Eigen::VectorXd &b){
  Eigen::PartialPivLU<Eigen::MatrixXd> lu(A);
  return lu.solve(b);
}

Eigen::VectorXd qr(const Eigen::MatrixXd &A, const Eigen::VectorXd &b){
  Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(A);
  return qr.solve(b);
}

Eigen::VectorXd svd(const Eigen::MatrixXd &A, const Eigen::VectorXd &b){
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);
  return svd.solve(b);
}


Eigen::VectorXd gaussSeidel(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const uint nbIter){
	
	Eigen::VectorXd x = b;

	for(uint iter=0; iter < nbIter; ++iter){
		for(int i=0; i<A.cols(); ++i){
			double sum = 0.0;
			for(int j= 0; j<A.rows(); ++j){
				if( i!= j)
					sum += A(i, j) * x(j);
				x(i) = (b(i)-sum)/A(i,i);
			}
		}
	}

	return x;
}

int main()
{
  srand(time(0));

  size_t dimension = 15;
  /*Eigen::MatrixXd A = Eigen::MatrixXd::Random(dimension, dimension) ;//+ Eigen::MatrixXd::Identity(dimension, dimension)*dimension;
  Eigen::VectorXd b = Eigen::VectorXd::Random(dimension);*/

  Eigen::Matrix2d A;
  A << 1e-3, 1,
  	1, 1;
  Eigen::Vector2d b;
  b << 1, 2;
  Eigen::VectorXd X;

  std::cout << "**************METHODE GAUSS-SEIDEL**************" << std::endl;
  clock_t begin1 = clock();
  X = gaussSeidel(A, b, 13);
  clock_t end1 = clock();
  double temps1 = double(end1 - begin1) / CLOCKS_PER_SEC;
  std::cout << "Norme : " << (A*X - b).norm() << std::endl;
  std::cout << "Temps : " << temps1 << std::endl;

  std::cout << "**************RESULTAT**************" << std::endl;
  std::cout << X.transpose() << std::endl;
  std::cout << std::endl;

  std::cout << "**************METHODE LU**************" << std::endl;
  clock_t begin2 = clock();
  X = lu(A, b);
  clock_t end2 = clock();
  double temps2 = double(end2 - begin2) / CLOCKS_PER_SEC;
  std::cout << "Norme : " << (A*X - b).norm() << std::endl;
  std::cout << "Temps : " << temps2 << std::endl;

  std::cout << "**************RESULTAT**************" << std::endl;
  std::cout << X.transpose() << std::endl;
  std::cout << std::endl;

  std::cout << "**************METHODE QR**************" << std::endl;
  clock_t begin3 = clock();
  X = qr(A, b);
  clock_t end3 = clock();
  double temps3 = double(end3 - begin3) / CLOCKS_PER_SEC;
  std::cout << "Norme : " << (A*X - b).norm() << std::endl;
  std::cout << "Temps : " << temps3 << std::endl;

  std::cout << "**************RESULTAT**************" << std::endl;
  std::cout << X.transpose() << std::endl;
  std::cout << std::endl;

  std::cout << "**************METHODE SVD**************" << std::endl;
  clock_t begin4 = clock();
  X = svd(A, b);
  clock_t end4 = clock();
  double temps4 = double(end4 - begin4) / CLOCKS_PER_SEC;
  std::cout << "Norme : " << (A*X - b).norm() << std::endl;
  std::cout << "Temps : " << temps4 << std::endl;

  std::cout << "**************RESULTAT**************" << std::endl;
  std::cout << X.transpose() << std::endl;
  std::cout << std::endl;

  return 0;
}



 //g++ -Wall -I ~/eigen/  eigenSample.cpp 
