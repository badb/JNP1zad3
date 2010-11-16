#include <iostream>
#include<time.h>
#include<cstdio>
#include<assert.h>
#include "rational.h"

using namespace std;

/*
 * 
 */
int main() {
	Rational r1;
	Rational r2(-40);
	Rational r3(3, 15);
	Rational r4(1, -12);
	Rational r5(r3);
	Rational r6(-48,-6);
	Rational r7(57, 14);
	cout << "r1 = " << r1 << " r1.n() = " << r1.n() << " r1.d() = " << r1.d() << endl;
	cout << "r2 = " << r2 << " r2.n() = " << r2.n() << " r2.d() = " << r2.d()<< endl;
	cout << "r3 = " << r3 << " r3.n() = " << r3.n() << " r3.d() = " << r3.d()<< endl;
	cout << "r4 = " << r4 << " r4.n() = " << r4.n() << " r4.d() = " << r4.d()<< endl;
	cout << "r5 = " << r5 << " r5.n() = " << r5.n() << " r5.d() = " << r5.d()<< endl;
	cout << "r6 = " << r6 << " r6.n() = " << r6.n() << " r6.d() = " << r6.d()<< endl;
	cout << "r7 = " << r7 << " r7.n() = " << r7.n() << " r7.d() = " << r7.d()<< endl;
	r5 = r4;
	cout << "r5 = " << r5 << " r5.n() = " << r5.n() << " r5.d() = " << r5.d()<< endl;
	r6 = 9;
	cout << "r6 = " << r6 << " r6.n() = " << r6.n() << " r6.d() = " << r6.d()<< endl;
	r5 = -r4;
	cout << "r5 = " << r5 << " r5.n() = " << r5.n() << " r5.d() = " << r5.d()<< endl;
	if (r4)
		cout << "Jest dobrze 1" << endl;
	else 
		cout << "Jest zle" << endl;
	Rational b1(5, 0);
	Rational b2(0, 0);
	cout << "b1 = " << b1 << " b1.n() = " << b1.n() << " b1.d() = " << b1.d() << endl;
	if (b1)
		cout << "Jest zle" << endl;
	else 
		cout << "Jest dobrze 2" << endl;
	if (r1 == r5)
		cout << "ZLE" << endl;
	else cout << "Jest dobrze 3" << endl;
	if (r1 != r5)
		cout << "Jest dobrze 4" << endl;
	else cout << "zle" << endl;
	if (b1 == r5)
		cout << "ZLE" << endl;
	else cout << "Jest dobrze 5" << endl;
	if (b1 != r5)
		cout << "zle" << endl;
	else cout << "Jest dobrze 6" << endl;
	if (r1 < r5)
		cout << "Jest dobrze 7" << endl;
	else cout << "zle" << endl;
	if (r1 > r5)
		cout << "zle" << endl;
	else cout << "Jest dobrze 8" << endl;
	if (b1 < r5)
		cout << "ZLE" << endl;
	else cout << "Jest dobrze 9" << endl;
	if (b1 > r5)
		cout << "zle" << endl;
	else cout << "Jest dobrze 10" << endl;
	if (r1 <= r5)
		cout << "Jest dobrze 11" << endl;
	else cout << "zle" << endl;
	if (r1 >= r5)
		cout << "zle" << endl;
	else cout << "Jest dobrze 12" << endl;
	if (b1 <= r5)
		cout << "ZLE" << endl;
	else cout << "Jest dobrze 13" << endl;
	if (b1 >= r5)
		cout << "zle" << endl;
	else cout << "Jest dobrze 14" << endl;
	if (r5 <= (-r4)) 
		cout << "Jest dobrze 15" << endl;
	else cout <<" zle" <<endl;
	if (b1 == b2)
		cout << "zle" << endl;
	else cout << "jest dobrze 16" <<endl;

 Rational t0(0,0); // r0 nie jest poprawn± liczb±.
 Rational t1(5,0); // r1 nie jest poprawn± liczb±.
 Rational t2(-3,0); // r2 nie jest poprawn± liczb±.
 Rational t3(5,2); // r3 jest poprawn± liczb±.
 Rational t4(t1); // r4 nie jest poprawn± liczb±.
 Rational t5 = t1 / t2; // r5 nie jest poprawn± liczb±.
 if (t0.isNumber())
	 cout << "zle" << endl;
 else cout << "jest dobrze 17" << endl;
 if (t1.isNumber())
	 cout << "zle" << endl;
 else cout << "jest dobrze 18" << endl;
  if (t2.isNumber())
	 cout << "zle" << endl;
 else cout << "jest dobrze 19" << endl;
  if (t3.isNumber())
	 cout << "jest dobrze 20" << endl;
 else cout << "zle" << endl;
  if (t4.isNumber())
	 cout << "zle" << endl;
 else cout << "jest dobrze 21" << endl;
  if (t5.isNumber())
	 cout << "zle" << endl;
 else cout << "jest dobrze 22" << endl;
 t3 += t1; // r3 nie jest ju¿ poprawn± liczb±.
  if (t3.isNumber())
	 cout << "zle" << endl;
 else cout << "jest dobrze 23" << endl;

cerr << r5 << endl;

cout << "(" << r1 << " + " << r5 << ") = " << r1 + r5 << endl;
cout << "(" << r3 << " + " << r5 << ") = " << r3 + r5 << endl;
cout << "(" << Rational::One() << " + " << r5 << ") = " << Rational::One() + r5 << endl;
cout << "(" << Rational::Zero() << " + " << r2 << ") = " << Rational::Zero() + r2 << endl;
cout << "(" << 2 << " + " << r3 << ") = " << 2 + r3 << endl;
cout << "(" << r3 << " - " << r5 << ") = " << r3 - r5 << endl;
cout << "(" << r3 << " * " << r5 << ") = " << r3 * r5 << endl;
cout << "(" << r3 << " / " << r5 << ") = " << r3 / r5 << endl;
cout << "(" << r3 << " - " << 3 << ") = " << r3 - 3 << endl;
cout << "(" << r3 << " * " << -5 << ") = " << r3 * (-5) << endl;
cout << "(" << r3 << " / " << 10 << ") = " << r3 / 10 << endl;
cout << "(" << r3 << " + " << 2 << ") = " << r3 + 2 << endl;
cout << "(" << 3 << " - " << r5 << ") = " << 3 - r5 << endl;
cout << "(" << 3 << " * " << r5 << ") = " << 3 * r5 << endl;
cout << "(" << 3 << " / " << r5 << ") = " << 3 / r5 << endl;

cout << "(" << b1 << " + " << r5 << ") = " << b1 + r5 << endl;
cout << "(" << r3 << " + " << b1 << ") = " << r3 + b1 << endl;
cout << "(" << Rational::One() << " + " << b1 << ") = " << Rational::One() + b1 << endl;
cout << "(" << Rational::Zero() << " + " << b1 << ") = " << Rational::Zero() + b1 << endl;
cout << "(" << 2 << " + " << b1 << ") = " << 2 + b1 << endl;
cout << "(" << r3 << " - " << b1 << ") = " << r3 - b1 << endl;
cout << "(" << r3 << " * " << b1 << ") = " << r3 * b1 << endl;
cout << "(" << b1 << " / " << r5 << ") = " << b1 / r5 << endl;
cout << "(" << b1 << " - " << 3 << ") = " << b1 - 3 << endl;
cout << "(" << b1 << " * " << -5 << ") = " << b1 * (-5) << endl;
cout << "(" << b1 << " / " << 10 << ") = " << b1 / 10 << endl;
cout << "(" << b1 << " + " << 2 << ") = " << b1 + 2 << endl;
cout << "(" << 3 << " - " << b1 << ") = " << 3 - b1 << endl;
cout << "(" << 3 << " * " << b1 << ") = " << 3 * b1 << endl;
cout << "(" << 3 << " / " << b1 << ") = " << 3 / b1 << endl;


cout << "(" << r1 << " + " << r2 << ") = ";
r1 += r2;
cout << r1 << endl;
cout << "(" << r1 << " - " << r3 << ") = ";
r1 -= r3;
cout << r1 << endl;
cout << "(" << r1 << " * " << r4 << ") = ";
r1 *= r4;
cout << r1 << endl;
cout << "(" << r1 << " / " << r5 << ") = ";
r1 /= r5;
cout << r1 << endl;
cout << "(" << r1 << " + " << 2 << ") = ";
r1 += 2;
cout << r1 << endl;
cout << "(" << r1 << " - " << 3 << ") = ";
r1 -= 3;
cout << r1 << endl;
cout << "(" << r1 << " * " << 4 << ") = ";
r1 *= 4;
cout << r1 << endl;
cout << "(" << r1 << " / " << 5 << ") = ";
r1 /= 5;
cout << r1 << endl;

cout << "(" << r1 << " + " << b1 << ") = ";
r1 += b1;
cout << r1 << endl;
r1 = r3;
cout << "(" << b1 << " - " << r1 << ") = ";
b1 -= r1;
cout << b1 << endl;
cout << "(" << b1 << " * " << r4 << ") = ";
b1 *= r4;
cout << b1 << endl;
cout << "(" << r1 << " / " << b1 << ") = ";
r1 /= b1;
cout << r1 << endl;
cout << "(" << b1 << " + " << 2 << ") = ";
b1 += 2;
cout << b1 << endl;
cout << "(" << b1 << " - " << 3 << ") = ";
b1 -= 3;
cout << b1 << endl;
cout << "(" << b1 << " * " << 4 << ") = ";
b1 *= 4;
cout << r1 << endl;
cout << "(" << b1 << " / " << 5 << ") = ";
b1 /= 5;
cout << r1 << endl;
	return 0;
}