#include <iostream>
#include <eigen3/Eigen/Dense>
#include <ctime>
#include <cassert>

Eigen::MatrixXd strassen(Eigen::MatrixXd mat1, Eigen::MatrixXd mat2){

  if(mat1.rows()<=128)
    return mat1*mat2;

  float a = mat1.topLeftCorner(rows, cols);
  float b = mat1.topRightCorner(rows, cols);
  float c = mat1.bottomLeftCorner(rows, cols);
  float d = mat1.bottomRightCorner(rows, cols);
  float e = mat2.topRightCorner(rows, cols);
  float f = mat2.topLeftCorner(rows, cols);
  float g = mat2.bottomLeftCorner(rows, cols);
  float h = mat2.bottomRightCorner(rows, cols);

  float P1 = strassen(a, (f-h));
  float P2 = strassen((a+b), h);
  float P3 = strassen((c+d), e);
  float P4 = strassen(d, (g-e));
  float P5 = strassen((a+d), (e+h));
  float P6 = strassen((b-d), (g+h));
  float P7 = strassen((a-c), (e+f));

  return Eigen::MatrixXd m << P5+P4-P2+P6, P1+P2,
                    P3+P4, P1+P5-P3-P7;
}

int main()
{
	
  int dimension;
  Eigen::MatrixXd mat1 = Eigen::MatrixXd::Random(dimension, dimension);  
  Eigen::MatrixXd mat2 = Eigen::MatrixXd::Random(dimension, dimension);  

  return 0;
}



 //g++ -Wall -I ~/eigen/  eigenSample.cpp 
