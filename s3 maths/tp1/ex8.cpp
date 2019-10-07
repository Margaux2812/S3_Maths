#include <iostream>
#include <iomanip>
#include <math.h> 
#include <string>
#include <vector>
#include <numeric>

#define imax 1000

int main()
{
  std::cout << "SERIE DE BÂLE" << std::endl;

  std::vector<float> numbers(imax);
  float sum;

  //On va de imax à 1 pour que quand on ajoute un petit nombre à un petit nombre ca va (vues les erreurs des float)
  for(int i = 1; i<imax ; i++){
    numbers[i] = 1.f/(i*i);
  }

  sum = std::accumulate(numbers.begin() + 1, numbers.end(), 0);

  std::cout << "La somme est " << sum << std::endl;

  return 0;
}
