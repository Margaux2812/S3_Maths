#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cassert>
#include <ctime>

double evalPolynomial(const Eigen::VectorXd &poly, const double x){
	double result = poly(0);
	double xIncremente = x;
	for(int i=1; i < poly.size(); i++){
		result += poly(i)*xIncremente;
		xIncremente *= x;
	}

	return result;
}

Eigen::VectorXd polynomialFromRoots(const Eigen::VectorXd &roots){
	Eigen::VectorXd poly(2);
	Eigen::VectorXd tmp(2);
	poly << 1, -roots(0);
	for(int i=1; i < roots.size(); i++){
		tmp.resize(poly.size()+1);
		tmp << 0, -roots(i)*poly;
		poly.conservativeResize(poly.size()+1);
		poly += tmp;
	}

	return poly;
}

Eigen::VectorXd polynomialFromRoots2(const Eigen::VectorXd &roots){
	Eigen::VectorXd p = Eigen::VectorXd::Ones(roots.size()+1);
	p(0) = -roots(0);
	for(int i=1; i < roots.size(); ++i){
		for(int j=i; j > 0; --j){
			p(j) = p(j-1) -roots(i)*p(j);
		}
		p(0) *= -roots(i);
	}

	return p;
}

int main()
{
	Eigen::VectorXd v(3);
	v << -1, 6, 3;
	Eigen::VectorXd w(4);
	w << 1, 2, 3, 4;
	std::cout << "On a le polynôme 3x²+6x-1. Au point x = 3 on a ce polynôme qui vaut " << evalPolynomial(v, 3) << std::endl;
	
	std::cout << "\n\nOn a le polynôme avec comme racines 1, 2, 3 et 4.\nOn a donc le polynôme avec comme facteurs"<< std::endl;
	clock_t begin = clock();
	Eigen::VectorXd res = polynomialFromRoots(w);
	clock_t end = clock();
	double tempsCalc1 = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << res  << std::endl;
	std::cout << "Ca a été fait en " << tempsCalc1 << std::endl;

	std::cout << "Et l'autre technique :" << std::endl;
	clock_t begin1 = clock();
	res = polynomialFromRoots2(w);
	clock_t end1 = clock();
	double tempsCalc2 = double(end1 - begin1) / CLOCKS_PER_SEC;
	std::cout << res  << std::endl;
	std::cout << "Ca a été fait en " << tempsCalc2 << std::endl;

	std::cout << "Au point x = 1 on a ce polynôme qui vaut " << evalPolynomial(res, 1) << std::endl;
	std::cout << "Au point x = 2 on a ce polynôme qui vaut " << evalPolynomial(res, 2) << std::endl;
	std::cout << "Au point x = 3 on a ce polynôme qui vaut " << evalPolynomial(res, 3) << std::endl;
	std::cout << "Au point x = 4 on a ce polynôme qui vaut " << evalPolynomial(res, 4) << std::endl;
	
  return 0;
}