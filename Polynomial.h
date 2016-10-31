/*
 *    Name: Luis Estrada
 *    Used: Dev-C++ 5.7.1 IDE on Windows 8.1 with GNU C++11
 */

#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include <vector>
#include <iostream>

using namespace std;

class Polynomial {
	private:
		int highestPower;
		vector<double> coefficients;
	public:
		Polynomial(); // default constructor
		void getPoly(); // create polynomial with user's input
		int degree() const; // return degree
		double coefficient(int) const; // return coefficient at chosen power
		void changeCoefficient(double, int); // change coefficient at chosen power
		void multiply(double); // multiply polynomial by a scalar
		Polynomial add(Polynomial); // add polynomials together
		void print(); // print polynomial
		
		/* overloaded operators */
		Polynomial operator/(double);
		Polynomial operator-();
		
};

/* overload << */
ostream& operator<< (ostream& outS, const  Polynomial& poly);

#endif
