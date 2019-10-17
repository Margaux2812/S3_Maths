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

int main()
{
	
  srand(time(0));

  const size_t dimension = 10000000;
  Eigen::VectorXd vec1 = Eigen::VectorXd::Random(dimension);
  Eigen::VectorXd vec2 = Eigen::VectorXd::Random(dimension);

  double res, res2;

  clock_t begin = clock();
  res = dot(vec1, vec2);
  clock_t end = clock();
  double tempsCalc1 = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << "temps calcul du produit scalaire avec notre dot: " <<tempsCalc1 <<"s" << std::endl;
  
  clock_t begin1 = clock();
  res2 = vec1.dot(vec2);
  clock_t end1 = clock();
  double tempsCalc2 = double(end1 - begin1) / CLOCKS_PER_SEC;

  std::cout << "temps calcul du produit scalaire avec la fonction dot de Eigen: " <<tempsCalc2 <<"s " << std::endl;
  
  std::cout << "Difference de resultat : " << abs(res-res2) << std::endl;

  return 0;
}



 //g++ -Wall -I ~/eigen/  eigenSample.cpp 
