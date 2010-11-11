#include<iostream>
#include"rational.h"

using namespace std;

/*implementacja Rational*/
/* konstruktory / destruktory */
Rational::Rational(): numerator(0), denominator(1), nan(false){

}
Rational::Rational(Integer i): numerator(i), denominator(1), nan(false){

}
Rational::Rational(Integer n, Unsigned d): numerator(n), denominator(d), nan(false){

}
Rational::Rational(const Rational& r): nan(false){

}
Rational::~Rational(){

}

Integer Rational::n(){
    return numerator;
}
Unsigned Rational::d(){
    return denominator;
}
bool Rational::isNumber(){
    return (!nan) && (denominator != 0);
}

/* tu źle ale później*/
static Rational Rational::Zero(){
    return Rational(0);
}
static Rational Rational::One(){
    return Rational(1);
}

/*operatory */
bool Rational::operator<(const Rational& r) const{
    //ułamki są skrócone!
    bool ret;
    ret = this->isNumber();
    ret &&= r.isNumber();
    ret &&= r.n() * this->d() < r.d() * this->n();
    return ret;
}
bool Rational::operator==(const Rational& r) const{
    //ułamki są skrócone!
    bool ret;
    ret = this->isNumber();
    ret &&= r.isNumber();
    ret &&= r.n() == this->n();
    ret &&= r.d() == this->d();
    return ret;
}
Rational& Rational::operator+=(const Rational& r){
    numerator *= r.d();
    numerator += r.n() * denominator;
    denominator *= r.d();
    /*można może lepiej dzięki NWW*/
    nan &&= r.isNumber();
    
    //na końcu skracaj nowy ułamek
    this->frac();
    return *this;
}
Rational& Rational::operator-=(const Rational& r){
    numerator *= r.d();
    numerator -= r.n() * denominator;
    denominator *= r.d();

    this->frac();
    return *this;
}
Rational& Rational::operator*=(const Rational& r){
    numerator *= r.n();
    denominator *= r.d();
    this->frac();
    return *this;
}
Rational& Rational::operator/=(const Rational& r){
    numerator *= r.d();
    denominator *= r.n();
    this->frac();
    return *this;
}
Rational& Rational::operator=(const Rational& r){
    numerator = r.n();
    denominator = r.d();
    return *this;
}
Rational& Rational::operator=(const Integer& i){
    numerator = i;
    denominator = 1;
    return *this;
}
Rational& Rational::operator-(){
    numerator = -numerator;
    return *this;
}

//przy wywołaniu ABS
static Unsigned Rational::NWD(Unsigned a, Unsigned b){
    Unsigned tmp = 0;
    while(b){
        tmp = b;
        b = a % b;
        a = tmp;
    }
}
void Rational::frac(){
    Integer nwd = NWD(ABS(numerator), denominator);
    numerator /= nwd;
    denominator /= nwd;
}
/* koniec implementacji Rational */