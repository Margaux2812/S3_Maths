#include <iostream>
#include <eigen3/Eigen/Dense>
#include <ctime>
#include <cassert>

double dot(const Eigen::VectorXd &vec1, const Eigen::VectorXd &vec2){
  assert(vec1.size() == vec2.size() && "Error : dot -> incompatible size");

  double sum=0.;

  for(unsigned int i=0; i< vec1.size(); i++){
    sum += vec1(i) * vec2(i);
  }

  return sum;
}

Eigen::MatrixXd prodMatr(const Eigen::MatrixXd &mat1, const Eigen::MatrixXd &mat2){
  assert(mat1.cols() == mat2.rows() && "Error : prodMatr -> incompatible size");

  Eigen::MatrixXd res(mat1.cols(), mat2.rows());

  for(unsigned int i=0; i< mat1.cols(); i++){
    for(unsigned int j=0; j<mat2.rows(); j++){
      res(i, j) = (mat1.row(i)).dot(mat2.col(j));
    }
  }

  return res;
}

Eigen::MatrixXd prodMatr2(const Eigen::MatrixXd &mat1, const Eigen::MatrixXd &mat2){
  assert(mat1.cols() == mat2.rows() && "Error : prodMatr -> incompatible size");

  Eigen::MatrixXd res(mat1.cols(), mat2.rows());

  for(unsigned int i=0; i< mat1.cols(); i++){
    for(unsigned int j=0; j<mat2.rows(); j++){
      res(i, j) = dot(mat1.row(i), mat2.col(j));
    }
  }

  return res;
}

Eigen::MatrixXd prodMatr3(const Eigen::MatrixXd &mat1, const Eigen::MatrixXd &mat2){
  assert(mat1.cols() == mat2.rows() && "Error : prodMatr -> incompatible size");

  Eigen::MatrixXd res(mat1.cols(), mat2.rows());

  for(unsigned int i=0; i< res.rows(); i++){

    for(unsigned int k=0; k< mat1.cols(); k++){
      for(unsigned int j=0; j<res.cols(); j++){
        res(i, j) += mat1(i, k) * mat2(k, j);
      }
    }
  }

  return res;
}

int main()
{
	
  srand(time(0));

  const size_t dimension = 1500;
  Eigen::MatrixXd mat1 = Eigen::MatrixXd::Random(dimension, dimension);
  Eigen::MatrixXd mat2 = Eigen::MatrixXd::Random(dimension, dimension);

  Eigen::MatrixXd res(dimension, dimension), res2(dimension, dimension), res3(dimension, dimension), res4(dimension, dimension), res5(dimension, dimension);

  clock_t begin = clock();
  res = mat1*mat2;
  clock_t end = clock();
  double tempsCalc1 = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << "temps calcul du produit scalaire avec prodMatr de Eigen: " <<tempsCalc1 <<"s\n\n" << std::endl;
  
  clock_t begin1 = clock();
  res2 = prodMatr(mat1, mat2);
  clock_t end1 = clock();
  double tempsCalc2 = double(end1 - begin1) / CLOCKS_PER_SEC;

  std::cout << "temps calcul du produit scalaire avec notre prodMatr: \n On utilise le dot de Eigen et on obtient : " <<tempsCalc2 <<"s\n\n " << std::endl;

  clock_t begin2 = clock();
  res3 = prodMatr2(mat1, mat2);
  clock_t end2 = clock();
  double tempsCalc3 = double(end2 - begin2) / CLOCKS_PER_SEC;

  std::cout << "temps calcul du produit scalaire avec prodMatr2 : \n On utilise notre dot et on obtient : " <<tempsCalc3 <<"s\n\n" << std::endl;

  clock_t begin3 = clock();
  res4 = prodMatr3(mat1, mat2);
  clock_t end3 = clock();
  double tempsCalc4 = double(end3 - begin3) / CLOCKS_PER_SEC;

  std::cout << "temps calcul du produit scalaire avec prodMatr3 : \n On a les 3 boucles for et on obtient : " <<tempsCalc4 <<"s\n\n" << std::endl;

  std::cout << "Difference de resultat : " << (res-res2).norm() << std::endl;

  return 0;
}



 //g++ -Wall -I ~/eigen/  eigenSample.cpp 
