#include <iostream>
#include <iomanip>
#include <math.h> 
#include <string>
#include <vector>
#include <numeric>

#define PRECISION 0.00001

double mySqrt(const float x){

  double rang = 0;

  while(x > rang*rang){
    rang++;
  }

  rang--;

 while(x > rang*rang){
  rang += PRECISION;
 }

std::cout << std::setprecision(20) <<rang<<std::endl;

  return rang;
}

double newton(const double x){
  const unsigned int MAX = 10;
  double un = 1;
  unsigned int n=0;

  while(n<MAX){
    un = (un+x/un)/2;
    n++;
  }

  std::cout << std::setprecision(20) <<un<<std::endl;
  return un;
}

int main()
{

  mySqrt(123);
  newton(123);

  return 0;
}
