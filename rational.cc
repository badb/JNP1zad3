#include<iostream>
#include"rational.h"

using namespace std;

/*implementacja Rational*/
/* konstruktory / destruktory */
Rational::Rational(const Rational& r){
    numerator = r.n();
    denominator = r.d();
}
Rational::~Rational(){
    
}

Integer Rational::n() const{
    return numerator;
}
Unsigned Rational::d() const{
    return denominator;
}
bool Rational::isNumber() const{
    return (denominator != 0);
}

/* tu źle ale później*/
const Rational& Rational::Zero(){
    static Rational* zero = new Rational(0);
    return *zero;
}
const Rational& Rational::One(){
    static Rational* one = new Rational(1);
    return *one;
}

/*operatory */
bool Rational::operator<(const Rational& r) const{
    //ułamki są skrócone!
    return
        this->isNumber()
        && r.isNumber()
        && r.d() * this->n() < r.n() * this->d();
}
bool Rational::operator==(const Rational& r) const{
    //ułamki są skrócone!
    return
        this->isNumber()
        && r.isNumber()
        && r.n() == this->n()
        && r.d() == this->d();
}

bool Rational::operator!=(const Rational& r) const {
	return
		(this->isNumber()
		&& r.isNumber())
		&& !(r == *this);
}

Rational& Rational::operator+=(const Rational& r){
    numerator *= r.d();
    numerator += r.n() * denominator;
    denominator *= r.d(); //jeżeli denominator = 0
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

Rational operator-(const Integer& i, const Rational& r) {
	return Rational(i * r.d() - r.n(), r.d());
}

Rational operator/(const Integer& i, const Rational& r) {
	return Rational(i * r.d(), r.n());
}

//przy wywołaniu ABS
const Unsigned Rational::NWD(Unsigned a, Unsigned b){
    Unsigned tmp = 0;
    while(b){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
void Rational::frac(){
    //sprawdzaj czy number
    if ((numerator != 0) && (denominator > 0)){
        Integer nwd = NWD(ABS(numerator), denominator);
        numerator /= nwd;
        denominator /= nwd;
    }
}
/* koniec implementacji Rational */

extern ostream& operator<<(ostream& os, const Rational& r) {
    if (r.isNumber()){
        Integer i = r.n() / Integer(r.d()); // n nie ma w mianowniku 0
        Integer m = r.n() % Integer(r.d());
        if(i!=0) os << i;
        if((i!=0) && (m!=0)) {
            if(m>0) os << "+";
        } else if ((i==0) && (m==0)){
            os << i;
        }
        if(m!=0) os << m << "/" << r.d();
    } else {
        os << "NaN";
    }
    return os;
}