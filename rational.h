#ifndef RATIONAL_H
#define RATIONAL_H
#include<boost/operators.hpp>
#include<iostream>

using namespace std;

/*
 *zastanowić się czy nie zmienić na jakąś klasę opakowującą long
 *jak w przykładowym rational.cc
 * jeżeli to nie jest potrzebne (np jeżeli nie wystąpi
 * niechciana konwersja)
 * to chyba nie ma sensu tak robić)
 */
typedef long Integer;
typedef unsigned long Unsigned;

class Rational : boost::operators<Rational>{
public:
    /* konstruktory / destruktory */
    Rational(); //tworzy ułamek 0
    Rational(Integer i); //tworzy na podstawie i
    Rational(Integer n, Unsigned d);
    Rational(const Rational& r);
    ~Rational();

    Integer n();   //returns numerator (skraca)
    Unsigned d();   //returns denominator
    bool isNumber();    //czy jest poprawna

    Rational Zero();
    Rational One();

    /*operatory - reszta wytworzona przez boost*/
    /*ps to trzeba sprawdzić bo ja boosta nigdy nie uzywałem*/
    operator bool_type() const{ // The Safe Bool Idiom
        return ( isNumber() && (numerator!=0) )? &Rational::type_no_comparisions : 0;
    }
    bool operator<(const Rational& r) const;
    bool operator==(const Rational& r) const; //dzieki < reszta porównywań automatycznie
    Rational& operator+=(const Rational& r); // + automatycznie
    Rational& operator+=(const Integer& i);
    Rational& operator-=(const Rational& r);// - automatycznie
    Rational& operator-=(const Integer& i);
    Rational& operator*=(const Rational& r);// * automatycznie
    Rational& operator*=(const Integer& i);
    Rational& operator/=(const Rational& r);// / automatycznie
    Rational& operator/=(const Integer& i);
    Rational& operator=(const Rational& r);
    Rational& operator=(const Integer& i);
    Rational& operator-(); //odwrotna do this


    
private:
    Integer numerator;
    Unsigned denominator;

    static Unsigned NWD(Unsigned a, Unsigned b);
    static Unsigned ABS(Integer a){
        return (a>0)?a:-a;
    }

    void frac(); //skracanie
    

    //The Safe Bool Idiom
    typedef void (Rational::*bool_type)() const;
    void type_no_comparisions() const {}
};

extern ostream& operator<<(ostream& os, const Rational& r);
#endif