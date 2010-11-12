#include <iostream>
#include<time.h>
#include<cstdio>
#include<assert.h>
#include "rational.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    const int MAX = 1000;
    const Integer ZAKRES = 1000000L;

    /* testy poprawność*/
    Rational r1; //ułamek zerowy
    Rational r2(12);//z liczby całkowitej
    Rational r3(12,13);//12/13
    Rational r4(r1); //ułamek zerowy
    Rational r5(0,0); //niepoprawny

    cout << "r1" << r1 << endl;
    cout << "r2" <<  r2 << endl;
    cout << "r3" <<  r3 << endl;
    cout << "r4" <<  r4 << endl;
    cout << "r5" <<  r5 << endl;

    r1 += r2;
    assert(r1==r2);
    r1 /= r3;
    assert(r1==Rational(13));
    r1 /= r2;
    assert(r1==Rational(13,12));
    r3 += r5; //r3==nan
    assert(!r3.isNumber());
    assert(r4==Rational(0);
    assert(r1);
    assert(!r5);
    assert(!r4);
    
    cout << "r1" << r1 << endl;
    cout << "r2" <<  r2 << endl;
    cout << "r3" <<  r3 << endl;
    cout << "r4" <<  r4 << endl;
    cout << "r5" <<  r5 << endl;


    /*testy stress*/
    Rational rTab[MAX];
    //przypisz coś
    for(Integer i =0; i<MAX; i++){
        rTab[i] += rand() % ZAKRES;
        rTab[i] /= rand() % ZAKRES;
        (rand() %2 == 1) rTab[i] = -rTab[i]; // niektóre odwrotne
    }
    
    //różne operacje
    for(Integer i=0; i<ZAKRES; i++){
        rTab[rand() % MAX] += rTab[rand() % MAX];
        rTab[rand() % MAX] += rand() % ZAKRES;
        rTab[rand() % MAX] -= rTab[rand() % MAX];
        rTab[rand() % MAX] -= rand() % ZAKRES;
        rTab[rand() % MAX] *= rTab[rand() % MAX];
        rTab[rand() % MAX] *= rand() % ZAKRES;
        rTab[rand() % MAX] /= rTab[rand() % MAX];
        rTab[rand() % MAX] /= rand() % ZAKRES;

        rTab[rand() % MAX] = rTab[rand() % MAX] + rTab[rand() % MAX];
        rTab[rand() % MAX] = rTab[rand() % MAX] + (rand() % ZAKRES);
        rTab[rand() % MAX] = rTab[rand() % MAX] - rTab[rand() % MAX];
        rTab[rand() % MAX] = rTab[rand() % MAX] - (rand() % ZAKRES);
        rTab[rand() % MAX] = rTab[rand() % MAX] * rTab[rand() % MAX];
        rTab[rand() % MAX] = rTab[rand() % MAX] * (rand() % ZAKRES);
        rTab[rand() % MAX] = rTab[rand() % MAX] / rTab[rand() % MAX];
        rTab[rand() % MAX] = rTab[rand() % MAX] / (rand() % ZAKRES);
    }

    for(Integer i =0; i<MAX; i++){
        cout << rTab[i];
    }
    cout << endl;

    return 0;
}