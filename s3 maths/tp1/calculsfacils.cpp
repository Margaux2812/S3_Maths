#include <iostream>
#include <iomanip> 

int main()
{
  std::cout << "0.1 + 0.2   = " << 0.1 + 0.2 << std::endl;
  std::cout << std::setprecision(40) << "0.1f + 0.2f = " << 0.1f + 0.2f << std::endl;    
  std::cout << std::setprecision(40) << "0.1  + 0.2  = " << 0.1  + 0.2  << std::endl;      
  std::cout << std::setprecision(40) << "0.1L + 0.2L = " << 0.1L + 0.2L << std::endl;      

  std::cout << std::endl;
  std::cout << std::setprecision(40) << "0.1f - 0.1L = " << 0.1f - 0.1L << std::endl;      

  return 0;
}
