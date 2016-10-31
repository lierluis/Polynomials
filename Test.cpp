/*
 *    Name: Luis Estrada
 *    Used: Dev-C++ 5.7.1 IDE on Windows 8.1 with GNU C++11
 */

#include "Polynomial.h"
#include <iostream>

using namespace std;

int main() {
	
	Polynomial poly1;
	poly1.getPoly();
	cout << "\n======= poly1 =======\n\n";
	poly1.print();
	
	Polynomial poly2;
	poly2.getPoly();
	cout << "\n======= poly2 =======\n\n";
	poly2.print();
	
	int x = -1;
	while (x != 0) {
		cout << "What would you like to do?\n";
		cout << "0-exit, 1-new poly, 2-degree, 3-coeff, 4-new coeff, 5-multiply by scalar\n";
		cout << "6-add, 7-print, 8-divide by scalar, 9-negate, 10-output on output stream\n";
		cout << "Choice: ";
		cin >> x;
		cout << endl;
		switch(x) {
			case 0: 
				cout << "Bye!";
				break;
			case 1: { // new poly
				int choice = 0;
				cout << "Which poly to replace? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					poly1.getPoly();
					cout << "\n======= poly1 =======\n\n";
					poly1.print();
				} else if (choice == 2) {
					poly2.getPoly();
					cout << "\n======= poly2 =======\n\n";
					poly2.print();
				} else {
					cout << "Incorrect input.";
				}
				break;
			}
			case 2: { // get degree
				int choice = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					cout << "\nPoly1 degree: " << poly1.degree() << "\n\n";
				} else if (choice == 2) {
					cout << "\nPoly2 degree: " << poly2.degree() << "\n\n";
				} else {
					cout << "Incorrect input.";
				}
				break;
			}
			case 3: { // get coefficient
				int choice = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					cout << "Enter power of variable to see coefficient: ";
					cin >> choice;
					if (choice > poly1.degree()) {
						cout << "Incorrect input.\n\n";
					} else {
						cout << "\nCoefficient: " << poly1.coefficient(choice) << "\n\n";
					}
				} else if (choice == 2) {
					cout << "Enter power of variable to see coefficient: ";
					cin >> choice;
					if (choice > poly2.degree()) {
						cout << "Incorrect input.\n\n";
					} else {
						cout << "Coefficient: " << poly2.coefficient(choice) << "\n\n";
					}
				} else {
					cout << "Incorrect input.\n\n";
				}
				break;
			}
			case 4: { // change coefficient
				int choice = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				double newCoef = 0;
				int pow = -1;
				if (choice == 1) {
					cout << "Enter power of variable whos coefficient you want to change: ";
					cin >> pow;
					cout << "Enter new coefficient: ";
					cin >> newCoef;
					poly1.changeCoefficient(newCoef, pow);
					cout << "\n======= poly1 =======\n\n";
					poly1.print();
				} else if (choice == 2) {
					cout << "Enter power of variable whos coefficient you want to change: ";
					cin >> pow;
					cout << "Enter new coefficient: ";
					cin >> newCoef;
					poly2.changeCoefficient(newCoef, pow);
					cout << "\n======= poly2 =======\n\n";
					poly2.print();
				} else {
					cout << "Incorrect input.\n\n";
				}
				break;
			}
			case 5: { // multiply by scalar
				int choice = 0;
				double scalar = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					cout << "Multiply poly1 by what scalar value? (e.g. 5): ";
					cin >> scalar;
					poly1.multiply(scalar);
					cout << "\n======= poly1 =======\n\n";
					poly1.print();
				} else if (choice == 2) {
					cout << "Multiply poly2 by what scalar value? (e.g. 5): ";
					cin >> scalar;
					poly2.multiply(scalar);
					cout << "\n======= poly2 =======\n\n";
					poly2.print();
				} else {
					cout << "Incorrect input.\n\n";
				}
				break;
			}
			case 6: { // add
				Polynomial sum;
				sum = poly1.add(poly2);
				cout << "======= poly1 =======\n\n";
				poly1.print();
				cout << "======= poly2 =======\n\n";
				poly2.print();
				cout << "=== poly1 + poly2 ===\n\n";
				sum.print();
				break;
			}
			case 7: { // print
				int choice = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					cout << "\n======= poly1 =======\n\n";
					poly1.print();
				} else if (choice == 2) {
					cout << "\n======= poly2 =======\n\n";
					poly2.print();
				} else {
					cout << "Incorrect input.\n\n";
				}
				break;
			}
			case 8: { // divide by scalar
				int choice = 0;
				double scalar = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					cout << "Enter scalar: ";
					cin >> scalar;
					cout << "\n======= poly1 =======\n\n";
					poly1 = poly1 / scalar;
					poly1.print();
				} else if (choice == 2) {
					cout << "Enter scalar: ";
					cin >> scalar;
					cout << "\n======= poly2 =======\n\n";
					poly2 = poly2 / scalar;
					poly2.print();
				} else {
					cout << "Incorrect input.";
				}
				break;
			}
			case 9: { // negate
				int choice = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					cout << "\n======= poly1 =======\n\n";
					poly1 = -poly1;
					poly1.print();
				} else if (choice == 2) {
					cout << "\n======= poly2 =======\n\n";
					poly2 = -poly2;
					poly2.print();
				} else {
					cout << "Incorrect input.";
				}
				break;
			}
			case 10: { // output stream
				int choice = 0;
				cout << "Which poly? Enter 1 or 2: ";
				cin >> choice;
				if (choice == 1) {
					cout << "\n======= poly1 =======\n\n";
					cout << poly1;
				} else if (choice == 2) {
					cout << "\n======= poly2 =======\n\n";
					cout << poly2;
				} else {
					cout << "Incorrect input.";
				}
				break;
			}
			default: {
				cout << "derp!" << endl;
			}
		}
	}
	
	return 0;
}
