#include <iostream>
#include <iomanip> 

int main()
{
  std::cout << "Voici les 100 premiers termes de la suite un avec des float" << std::endl;

  float U = 1./3.;
  std::cout << "U0" << " = 1/3"  << std::endl;
  for(int i=1; i<101; i++){

  	U = 4.*U - 1.;

  	std::cout << "U" << i << " = " << U<< std::endl;  

  }

  std::cout << "Voici les 100 premiers termes de la suite un avec des double" << std::endl;

  double u = 1./3.;
  std::cout << "U0" << " = 1/3"  << std::endl;
  for(int i=1; i<101; i++){

  	u = 4.*u - 1.;

  	std::cout << "U" << i << " = " << u<< std::endl;  

  }
    
  return 0;
}
