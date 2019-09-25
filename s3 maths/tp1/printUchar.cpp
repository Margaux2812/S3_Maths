#include <iostream>
#include <cstdlib>
#include <string>

std::string decToBi(unsigned char x){
	int puissance;
	std::string result;

	for(int i=0; i<8; i++){
		puissance = x%2;
		x = x/2;

		result = std::to_string(puissance) + result;
	}

	return result;
}

void correction(){
	for(int i=7; i>=0; --i){
		cout << (x>>i)&1;
	}
}

void printUchar(const unsigned char x)
{
  std :: cout << (int ) x << " : " << decToBi(x) << std::endl;
  std::cout << std::endl;
}


int main(int argc, char **argv)
{
  if(argc != 2){
    std::cerr << "usage: " << argv[0] << " nb" << std::endl;
    return 0;
  }
  printUchar(atoi(argv[1]));

  return 1;
}
