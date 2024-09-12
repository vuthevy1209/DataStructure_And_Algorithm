#pragma once
#include <string>
#include <iostream>
using namespace std;

struct bigint {
private:
    string number;
public:
    bigint();
    bigint(const string& num);
    bigint(const bigint& a);

    void setNumber(const string& num);
    string getNumber() const;
    bigint formatNumber();
    
    bigint operator + (const bigint& a) const;
    bigint operator - (const bigint& a) const;
    bigint operator * (const bigint& a) const;
    bigint operator / (const bigint& a) const;
    bigint operator % (const bigint& a) const;

    bool operator == (const bigint& a) const;
    bool operator != (const bigint& a) const;
    bool operator < (const bigint& a) const;
    bool operator <= (const bigint& a) const;
    bool operator > (const bigint& a) const;
    bool operator >= (const bigint& a) const;

    friend ostream& operator << (ostream& out, const bigint& a);
    friend istream& operator >> (istream& in, bigint& a);
};

//#include "BigNum.cpp"

