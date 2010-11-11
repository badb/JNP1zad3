#include<iostream>
#include"rational.h"

using namespace std;

/*implementacja Rational*/
/* konstruktory / destruktory */
Rational::Rational(): numerator(0), denominator(1){

}
Rational::Rational(Integer i): numerator(i), denominator(1){

}
Rational::Rational(Integer n, Unsigned d): numerator(n), denominator(d){

}
Rational::Rational(const Rational& r){
    numerator = r.n();
    denominator = r.d();
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
    return (denominator != 0);
}

/* tu źle ale później*/
Rational Rational::Zero(){
    static Rational* zero = new Rational(0);
    return *zero;
}
Rational Rational::One(){
    static Rational* one = new Rational(1);
    return *one;
}

/*operatory */
bool Rational::operator<(const Rational& r) const{
    //ułamki są skrócone!
    return
        this->isNumber();
        && r.isNumber();
        && r.n() * this->d() < r.d() * this->n();
}
bool Rational::operator==(const Rational& r) const{
    //ułamki są skrócone!
    return
        this->isNumber()
        && r.isNumber();
        && r.n() == this->n();
        && r.d() == this->d();
}
Rational& Rational::operator+=(const Rational& r){
    numerator *= r.d();
    numerator += r.n() * denominator;
    denominator *= r.d();
    /*można może lepiej dzięki NWW*/
    //jeżeli r była nan to w mianowniku bedzie 0 po operacju
    //wiec tez bedzie nan
    
    //na końcu skracaj nowy ułamek
    this->frac();
    return *this;
}
Rational& Rational::operator+=(const Integer& i){
    numerator += i * denominator;

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
Rational& Rational::operator-=(const Integer& i){
    numerator -= i * denominator;

    this->frac();
    return *this;
}
Rational& Rational::operator*=(const Rational& r){
    numerator *= r.n();
    denominator *= r.d();
    this->frac();
    return *this;
}
Rational& Rational::operator*=(const Integer&i){
    numerator *=i;
    this->frac();
    return *this;
}
Rational& Rational::operator/=(const Rational& r){
    if(r.isNumber()){
        numerator *= r.d();
        denominator *= r.n();
    } else {
        numerator = 0;
        denominator = 0;
    }
    this->frac();
    return *this;
}
Rational& Rational::operator/=(const Integer& i){
    denominator *= i;
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
    return a;
}
void Rational::frac(){
    Integer nwd = NWD(ABS(numerator), denominator);
    numerator /= nwd;
    denominator /= nwd;
}
/* koniec implementacji Rational */

extern ostream& operator<<(ostream& os, const Rational& r) {
    //narazie nie tak jak ma być, później się to zrobi
    os << r.n() << "/" << r.d();
    return os;
}