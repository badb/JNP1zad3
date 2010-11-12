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
    srand(time(0));
    const int MAX = 10;
    const Integer ZAKRES = 10L;
    const int ILEOPERACJI = 10;

    /* testy poprawność*/
    Rational r1; //ułamek zerowy
    Rational r2(12);//z liczby całkowitej
    Rational r3(12,13);//12/13
    Rational r4(r1); //ułamek zerowy
    Rational r5(0,0); //niepoprawny
    Rational r6 = r1.One();//tu jest zle ma byc do Rational
    Rational r7 = r1.Zero();//nie do obiektu
    Rational r8(4,3);//wypisywanie
    Rational r9(-15, 6);

    cout << "r1 " << r1 << endl;
    cout << "r2 " <<  r2 << endl;
    cout << "r3 " <<  r3 << endl;
    cout << "r4 " <<  r4 << endl;
    cout << "r5 " <<  r5 << endl;
    cout << "r6 " <<  r6 << endl;
    cout << "r7 " <<  r7 << endl;
    cout << "r8 " <<  r8 << endl;
    cout << "r9 " <<  r9 << endl;

    r1 += r2;
    assert(r1==r2);
    r1 /= r3;
    assert(r1==Rational(13));
    r1 /= r2;
    assert(r1==Rational(13,12));
    r3 += r5; //r3==nan
    assert(!r3.isNumber());
    assert(r4==Rational(0));
    assert(r1);
    assert(!r5);
    assert(!r4);
    r7 -= r6;
    assert(rt==Rational(-1));

    r9 = r8 + r7;
    
    cout << "r1 " << r1 << endl;
    cout << "r2 " <<  r2 << endl;
    cout << "r3 " <<  r3 << endl;
    cout << "r4 " <<  r4 << endl;
    cout << "r5 " <<  r5 << endl;
    cout << "r6 " <<  r6 << endl;
    cout << "r7 " <<  r7 << endl;
    cout << "r8 " <<  r8 << endl;
    cout << "r9 " <<  r9 << endl;

    
    /*testy stress*/
    Rational rTab[MAX];
    //przypisz coś
    for(Integer i =0; i<MAX; i++){
        rTab[i] = Rational(rand() % ZAKRES,rand() % ZAKRES);
        if (rand() %2 == 1)  rTab[i] = -rTab[i]; // niektóre odwrotne
        cout << "rTab[" << i << "] = " << rTab[i] << endl;
    }
    
    //różne operacje
    for(Integer i=0; i<ILEOPERACJI; i++){
        rTab[rand() % MAX] += rTab[rand() % MAX];
        rTab[rand() % MAX] += rand() % ZAKRES;
        rTab[rand() % MAX] -= rTab[rand() % MAX];
        rTab[rand() % MAX] -= rand() % ZAKRES;
        rTab[rand() % MAX] *= rTab[rand() % MAX];
        rTab[rand() % MAX] *= rand() % ZAKRES;
        rTab[rand() % MAX] /= rTab[rand() % MAX];
        rTab[rand() % MAX] /= rand() % ZAKRES;

        rTab[rand() % MAX] = rTab[rand() % MAX] + rTab[rand() % MAX];
        //rTab[rand() % MAX] = rTab[rand() % MAX] + (rand() % ZAKRES);
        rTab[rand() % MAX] = rTab[rand() % MAX] - rTab[rand() % MAX];
        //rTab[rand() % MAX] = rTab[rand() % MAX] - (rand() % ZAKRES);
        rTab[rand() % MAX] = rTab[rand() % MAX] * rTab[rand() % MAX];
        //rTab[rand() % MAX] = rTab[rand() % MAX] * (rand() % ZAKRES);
        rTab[rand() % MAX] = rTab[rand() % MAX] / rTab[rand() % MAX];
        //rTab[rand() % MAX] = rTab[rand() % MAX] / (rand() % ZAKRES);

    }

    for(Integer i =0; i<MAX; i++){
        cout << "rTab[" << i << "] = " << rTab[i] << endl;
    }
    cout << endl;

    return 0;
}