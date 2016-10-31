# Polynomials

Polynomial operations:
* Printing degrees and coefficients
* Multiplying/dividing by scalars
* Negation
* Addition
* Replacing & printing values

<hr>

Developed using Dev-C++ 5.7.1 IDE on Windows 8.1 with GNU C++11 compiler. To compile and run using Dev-C++, open `HW4-1.dev` and click on `Execute -> Compile & Run`.

Alternatively, to compile using a terminal, within the Polynomial directory, enter:

```
g++ *.cpp -std=c++11 -o output
```

To run, enter:

```
./output
```

<hr>

##### Sample run (simplified):

```
Enter the degree (highest power) of a polynomial: 2
Enter coefficient for X^0: 1
Enter coefficient for X^1: 4
Enter coefficient for X^2: 2

======= poly1 =======
2X^2 + 4X + 1

Enter the degree (highest power) of a polynomial: 1
Enter coefficient for X^0: 3
Enter coefficient for X^1: 1

======= poly2 =======
X + 3

What would you like to do?
0-exit, 1-new poly, 2-degree, 3-coeff, 4-new coeff, 5-multiply by scalar
6-add, 7-print, 8-divide by scalar, 9-negate, 10-output on output stream
```
```
Choice: 1

Which poly to replace? Enter 1 or 2: 2
Enter the degree (highest power) of a polynomial: 2
Enter coefficient for X^0: 4
Enter coefficient for X^1: 0
Enter coefficient for X^2: 2

======= poly2 =======
2X^2 + 4
```
```
Choice: 6

======= poly1 =======
2X^2 + 4X + 1

======= poly2 =======
2X^2 + 4

=== poly1 + poly2 ===
4X^2 + 4X + 5
```
```
Choice: 8

Which poly? Enter 1 or 2: 2
Enter scalar: 2

======= poly2 =======
X^2 + 2
```
```
Choice: 9

Which poly? Enter 1 or 2: 2

======= poly2 =======
-X^2 - 2
```
```
Choice: 5

Which poly? Enter 1 or 2: 1
Multiply poly1 by what scalar value? (e.g. 5): 2

======= poly1 =======
4X^2 + 8X + 2
```
```
Choice: 2

Which poly? Enter 1 or 2: 1

Poly1 degree: 2
```
```
Choice: 3

Which poly? Enter 1 or 2: 1
Enter power of variable (e.g. 5): 2

Coefficient: 4
```
```
Choice: 4

Which poly? Enter 1 or 2: 1
Enter power of variable whos coefficient you want to change: 2
Enter new coefficient: 1

======= poly1 =======

X^2 + 8X + 2
```
```
Choice: 7

Which poly? Enter 1 or 2: 1

======= poly1 =======
X^2 + 8X + 2
```
```
Choice: 10

Which poly? Enter 1 or 2: 2

======= poly2 =======
-X^2 - 2
```
```
Choice: 0

Bye!
```
