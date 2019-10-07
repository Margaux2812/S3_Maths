#include <iostream>
#include <iomanip>
#include <math.h> 
#include <string>

int main()
{
  int a, b, sommeResidu=0;
  std::string residuS = "";

  std::cout << "MULTIPLICATION A LA RUSSE\nChoisissez deux nombres à multiplier" << std::endl;

  std::cin >> a >> b;

  std::cout << a << " * " << b << " = " << std::endl;

  if(a>b)
    std::swap(a, b);

  while(a != 1){
    if(a & 1){ //Si c'est vrai, c'est 2^0 = 1 donc pas divisble par 2
      sommeResidu += b;
      residuS += std::to_string(b) + " + ";
    }
    a = a >> 1;
    b = b << 1;
  }

  residuS = residuS.substr(0, residuS.length() - 3);
  std::cout << b << " + (" << residuS << ") = " << sommeResidu + b << std::endl;

  return 0;
}
