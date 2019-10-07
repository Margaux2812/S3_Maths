#include <iostream>
#include <eigen3/Eigen/Dense>
#include <ctime>
int main()
{
	
  
  //Vector de dimension X et avec des doubles, v1(5) => 5 dimensions
  Eigen::VectorXd v1(5);
  v1 << 1, 2, 3, 4, 5; //Remplit le vecteur
  std::cout << "v1 : " << v1.transpose() << std::endl << std::endl;

  Eigen::Vector4f v2 = Eigen::Vector4f::Zero(); //Il est optimisé pour les op des vecteurs de taille 4
  std::cout << "v2 : " << v2.transpose() << std::endl << std::endl;

  v2 = Eigen::Vector4f::Ones();
  std::cout << "v2 : " << v2.transpose() << std::endl << std::endl;

  Eigen::Vector4f v3 = Eigen::Vector4f::Random();
  std::cout << "v3 : " << v3.transpose() << std::endl << std::endl;
  v3 = v3 + v2;
  std::cout << "v3 : " << v3.transpose() << std::endl << std::endl;

  Eigen::MatrixXd A = Eigen::MatrixXd::Random(3,4);	//Lignes puis colonnes
  std::cout << "A :\n" << A << std::endl << std::endl;

  Eigen::Matrix4d B = Eigen::Matrix4d::Random(4,4);	
  std::cout << "B :\n" << B << std::endl << std::endl;

  Eigen::MatrixXd C(3,4);
  
  clock_t begin = clock();
  C=A*B;
  clock_t end = clock();
  double tempsCalc = double(end - begin) / CLOCKS_PER_SEC;
  

  std::cout << "temps calcul du produit matriciel: " <<tempsCalc <<"s " << std::endl;
  std::cout << "A + 2*A :\n" << A + 2*A << std::endl << std::endl;
  std::cout << "A * B :\n" << A * B << std::endl << std::endl;
  A(0, 0) = 42;
  std::cout << "A : \n" << A << std::endl<<std::endl;

  v1(1) = 42;
  std::cout << "v1 : \n" << v1.transpose() << std::endl;

  //Acceder a un element A(i, j);

  return 0;
}



// g++ -Wall -I ~/eigen/  eigenSample.cpp 
