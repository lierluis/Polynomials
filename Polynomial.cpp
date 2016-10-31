/*
 *    Name: Luis Estrada
 *    Used: Dev-C++ 5.7.1 IDE on Windows 8.1 with GNU C++11
 */

#include "Polynomial.h"
#include <iostream>
#include <vector>

using namespace std;

/* default constructor */
Polynomial::Polynomial() {
	highestPower = 0;
	coefficients = {0};
}

/* creates a polynomial with inputs from user */
void Polynomial::getPoly() {
	cout << "Enter the degree (highest power) of a polynomial: ";
	cin >> highestPower;
	
	while (highestPower < 0) {
		cout << "Invalid input. Please input positive value: ";
		cin >> highestPower;
	}
	
	coefficients.resize(degree() + 1);
	for (int i = 0; i <= degree(); i++) {
		cout << "Enter coefficient for X^" << i << ": ";
		cin >> coefficients[i];
		
		// make sure degree is guaranteed, i.e. it can't be deleted with a 0 coefficient
		while (i == degree() && i !=0 && coefficient(i) == 0) {
			cout << "X^" << i << " coefficient cannot be zero, since you "
				 << "wanted a polynomial of degree " << degree() << ".\n";
			cout << "Re-enter coefficient for X^" << degree() << ": ";
			cin >> coefficients[i];
		}
		
	}
	//cout << endl;
}

/* Returns highest power (degree) */
int Polynomial::degree() const {
	return highestPower;
}

/* returns coefficient of the variable with the chosen power */
double Polynomial::coefficient(int power) const {
	return coefficients[power];
}

/* replaces coefficient of the variable with the chosen power */
void Polynomial::changeCoefficient(double newCoefficient, int power) {
	if (power > highestPower) {
		cout << "Error: cannot reach power of " << power << " to change coefficient." << endl;
	} else {
		coefficients[power] = newCoefficient;
	}
}

/* multiplies polynomial with a scalar value */
void Polynomial::multiply(double scalar) {
	for (int i = 0; i <= degree(); i++) {
		coefficients[i] = (coefficient(i) * scalar);
	}
}

/* adds two polynomials */
Polynomial Polynomial::add(Polynomial poly) {
	Polynomial sum;
	
	// if poly1's degree > poly2's degree
	if (degree() > poly.degree()) {
		sum.coefficients.resize(coefficients.size());
		sum.highestPower = degree();
		
		int difference = degree() - poly.degree();
		
		// add variables up to where they differ
		for (int i = 0; i < sum.coefficients.size() - difference; i++) {
			sum.coefficients[i] = coefficient(i) + poly.coefficient(i);
		}
		// add poly1's remaining variables into sum
		for (int i = sum.coefficients.size() - difference; i < sum.coefficients.size(); i++) {
			sum.coefficients[i] = coefficients[i];
		}
		
	  // if poly1's degree < poly2's degree
	} else if (degree() < poly.degree()){
		sum.coefficients.resize(poly.coefficients.size());
		sum.highestPower = poly.degree();
		
		int difference = poly.degree() - degree();
		
		// add variables up to where they differ
		for (int i = 0; i < sum.coefficients.size() - difference; i++) {
			sum.coefficients[i] = coefficient(i) + poly.coefficient(i);
		}
		// add poly2's remaining variables into sum
		for (int i = sum.coefficients.size() - difference; i < sum.coefficients.size(); i++) {
			sum.coefficients[i] = poly.coefficients[i];
		}
	
	  // if poly1's degree == poly2's degree
	} else {
		sum.coefficients.resize(coefficients.size());
		sum.highestPower = degree();
		
		// add variables together
		for (int i = 0; i < sum.coefficients.size(); i++) {
			sum.coefficients[i] = coefficient(i) + poly.coefficient(i);
		}
	}
	
	return sum;
}

/* prints polynomial (syntax heavy!) */
void Polynomial::print() {
	
	for (int i = degree(); i >= 0; i--) {
		
		// constant X^0
		if (degree() == 0) {
			
			// print coefficient
			if (coefficient(i) == 0) {
				cout << 0;
			} else {
				cout << coefficient(i);
			}
			
		  // X^1 + X^0
		} else if (degree() == 1) {
			
			if (i == 1) { // X^1
				if (coefficient(i) == 1) {
					cout << "X";
				} else if (coefficient(i) == -1) {
					cout << "-X";
				} else if (coefficient(i) > 1 || coefficient(i) < 1) {
					cout << coefficient(i) << "X";
				}
			} else if (i == 0) { // X^0
				if (coefficient(i) > 0) {
					cout << " + " << coefficient(i);
				} else if (coefficient(i) < 0) {
					cout << " - " << (coefficient(i) * -1);
				}
			}
			
		  // X^n + ... X^i + ... + X^1 + X^0
		} else if (degree() > 1) {
			
			if (i == degree()) { // X^n
				if (coefficient(i) == 1) {
					cout << "X^" << i;
				} else if (coefficient(i) == -1) {
					cout << "-X^" << i;
				} else if (coefficient(i) == 0) {
					
				} else {
					cout << coefficient(i) << "X^" << i;
				}
			} else if (i == 1) { // X^1
				if (coefficient(i) == 1) {
					cout << " + X";
				} else if (coefficient(i) == -1) {
					cout << " - X";
				} else if (coefficient(i) > 0) {
					cout << " + " << coefficient(i) << "X";
				} else if (coefficient(i) < 0) {
					cout << " - " << (coefficient(i) * -1) << "X";
				}
			} else if (i == 0) { // X^0
				if (coefficient(i) > 0) {
					cout << " + " << coefficient(i);
				} else if (coefficient(i) < 0) {
					cout << " - " << (coefficient(i) * -1);
				}
			} else { // X^i
				if (coefficient(i) == 1) {
					cout << " + X^" << i;
				} else if (coefficient(i) == -1) {
					cout << " - X^" << i;
				} else if (coefficient(i) > 1) {
					cout << " + " << coefficient(i) << "X^" << i;
				} else if (coefficient(i) < 0) {
					cout << " - " << (coefficient(i) * -1) << "X^" << i;
				}
			}
		}
		
	}
	cout << endl << endl;
}

/* divide polynomial by a scalar value */
Polynomial Polynomial::operator/(double scalar) {
	for (int i = 0; i < coefficients.size(); i++) {
		coefficients[i] = (coefficient(i) / scalar);
	}
	return *this;
}

/* negate polynomial */
Polynomial Polynomial::operator-() {
	for (int i = 0; i < coefficients.size(); i++) {
		coefficients[i] = -coefficients[i];
	}
	return *this;
}

/* output on output stream */
ostream& operator<< (ostream& outS, const Polynomial& poly) {
	for (int i = poly.degree(); i >= 0; i--) {
		
		// constant X^0
		if (poly.degree() == 0) {
			
			// print coefficient
			if (poly.coefficient(i) == 0) {
				outS << 0;
			} else {
				outS << poly.coefficient(i);
			}
			
		  // X^1 + X^0
		} else if (poly.degree() == 1) {
			
			if (i == 1) { // X^1
				if (poly.coefficient(i) == 1) {
					outS << "X";
				} else if (poly.coefficient(i) == -1) {
					outS << "-X";
				} else if (poly.coefficient(i) > 1 || poly.coefficient(i) < 1) {
					outS << poly.coefficient(i) << "X";
				}
			} else if (i == 0) { // X^0
				if (poly.coefficient(i) > 0) {
					outS << " + " << poly.coefficient(i);
				} else if (poly.coefficient(i) < 0) {
					outS << " - " << (poly.coefficient(i) * -1);
				}
			}
			
		  // X^n + ... X^i + ... + X^1 + X^0
		} else if (poly.degree() > 1) {
			
			if (i == poly.degree()) { // X^n
				if (poly.coefficient(i) == 1) {
					outS << "X^" << i;
				} else if (poly.coefficient(i) == -1) {
					outS << "-X^" << i;
				} else if (poly.coefficient(i) == 0) {
					
				} else {
					outS << poly.coefficient(i) << "X^" << i;
				}
			} else if (i == 1) { // X^1
				if (poly.coefficient(i) == 1) {
					outS << " + X";
				} else if (poly.coefficient(i) == -1) {
					outS << " - X";
				} else if (poly.coefficient(i) > 1) {
					outS << " + " << poly.coefficient(i) << "X";
				} else if (poly.coefficient(i) < 0) {
					outS << " - " << (poly.coefficient(i) * -1) << "X";
				}
			} else if (i == 0) { // X^0
				if (poly.coefficient(i) > 0) {
					outS << " + " << poly.coefficient(i);
				} else if (poly.coefficient(i) < 0) {
					outS << " - " << (poly.coefficient(i) * -1);
				}
			} else { // X^i
				if (poly.coefficient(i) == 1) {
					outS << " + X^" << i;
				} else if (poly.coefficient(i) == -1) {
					outS << " - X^" << i;
				} else if (poly.coefficient(i) > 1) {
					outS << " + " << poly.coefficient(i) << "X^" << i;
				} else if (poly.coefficient(i) < 0) {
					outS << " - " << (poly.coefficient(i) * -1) << "X^" << i;
				}
			}
		}
		
	}
	outS << endl << endl;
	
	return outS;
}
