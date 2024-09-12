#include "BigNum.h"

bigint::bigint() {
    number = "0";
}

bigint::bigint(const string& num) {
    this->number = num;
    formatNumber();
}

bigint::bigint(const bigint& a) {
    this->number = a.number;
}

void bigint::setNumber(const string& num) {
    number = num;
    formatNumber();
}

string bigint::getNumber() const {
    return number;
}

bigint bigint::formatNumber() {
    while (number.size() > 1 && number[0] == '0') {
        number.erase(0, 1);
    }
    if (number == "-0") number = "0";
    if (number[0] == '+') number.erase(0, 1);

    return *this;
}

bigint bigint::operator+(const bigint& a) const {
    string num1 = number;
    string num2 = a.number;

    if (num1[0] == '-' && num2[0] == '-') {
        return bigint("-" + (bigint(num1.erase(0, 1)) + bigint(num2.erase(0, 1))).number).formatNumber();
    }
    if (num1[0] == '-' && num2[0] != '-') {
        return bigint(num2) - bigint(num1.erase(0, 1)).formatNumber();
    }
    if (num1[0] != '-' && num2[0] == '-') {
        return bigint(num1) - bigint(num2.erase(0, 1)).formatNumber();
    }

    string result;
    int carry = 0;

    while (num1.size() < num2.size()) num1 = "0" + num1;
    while (num2.size() < num1.size()) num2 = "0" + num2;

    for (int i = num1.size() - 1; i >= 0; i--) {
        int sum = num1[i] - '0' + num2[i] - '0' + carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;
    }

    if (carry) result = to_string(carry) + result;

    return bigint(result);
}

bigint bigint::operator-(const bigint& a) const {
    string num1 = number;
    string num2 = a.number;

    if (num1[0] == '-' && num2[0] == '-') {
        return bigint(num2.erase(0, 1)) - bigint(num1.erase(0, 1)).formatNumber();
    }
    if (num1[0] == '-' && num2[0] != '-') {
        return bigint("-" + (bigint(num1.erase(0, 1)) + bigint(num2)).number).formatNumber();
    }
    if (num1[0] != '-' && num2[0] == '-') {
        return bigint(bigint(num1) + bigint(num2.erase(0, 1))).formatNumber();
    }
    if (bigint(num1) < bigint(num2)) {
        return bigint("-" + (bigint(num2) - bigint(num1)).number).formatNumber();
    }

    string result;
    int borrow = 0;

    while (num1.size() < num2.size()) num1 = "0" + num1;
    while (num2.size() < num1.size()) num2 = "0" + num2;

    for (int i = num1.size() - 1; i >= 0; i--) {
        int diff = num1[i] - '0' - (num2[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result = to_string(diff) + result;
    }

    return bigint(result).formatNumber();
}

bigint bigint::operator*(const bigint& a) const {
    string num1 = number;
    string num2 = a.number;

    if (num1[0] == '-' && num2[0] == '-') {
        return bigint(num1.erase(0, 1)) * bigint(num2.erase(0, 1)).formatNumber();
    }
    if (num1[0] == '-' && num2[0] != '-') {
        return bigint("-" + (bigint(num1.erase(0, 1)) * bigint(num2)).number).formatNumber();
    }
    if (num1[0] != '-' && num2[0] == '-') {
        return bigint("-" + (bigint(num1) * bigint(num2.erase(0, 1))).number).formatNumber();
    }

    string result(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');
            result[i + j + 1] = sum % 10 + '0';
            result[i + j] += sum / 10;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        if (result[i] != '0') {
            return bigint(result.substr(i)).formatNumber();
        }
    }

    return bigint("0");
}

int cmp(string a, string b)
{
    a.insert(0, max(0, (int)(b.length() - a.length())), '0');
    b.insert(0, max(0, (int)(a.length() - b.length())), '0');
    if (a > b) return 1;
    if (a == b) return 2;
    return 3;
}

bigint bigint::operator/(const bigint& a) const {
    if (a.number == "0") throw runtime_error("Division by zero: (" + number + " / " + a.number + ")");

    string num1 = number;
    string num2 = a.number;

    if (num1[0] == '-' && num2[0] == '-') {
        return bigint(num1.erase(0, 1)) / bigint(num2.erase(0, 1)).formatNumber();
    }
    if (num1[0] == '-' && num2[0] != '-') {
        return bigint("-" + (bigint(num1.erase(0, 1)) / bigint(num2)).number).formatNumber();
    }
    if (num1[0] != '-' && num2[0] == '-') {
        return bigint("-" + (bigint(num1) / bigint(num2.erase(0, 1))).number).formatNumber();
    }

    string  tb[11];
    tb[0] = "0";
    for (int i = 1; i <= 10; ++i) tb[i] = (bigint(tb[i - 1]) + bigint(num2)).number;

    string  hold = num1.substr(0, num2.length() - 1);
    string  res = "0";
    for (int i = num2.length() - 1; i <= (int)num1.length() - 1; ++i)
    {
        hold += num1[i];
        int k = 1;
        while (cmp(hold, tb[k]) != 3) ++k;
        res = res + (char)(k - 1 + 48);
        hold = (bigint(hold) - bigint(tb[k - 1])).number;
    }

    return bigint(res).formatNumber();

}

bigint bigint::operator%(const bigint& a) const {
    if (a.number == "0") throw runtime_error("Division by zero: (" + number + " % " + a.number + +")");

    string num1 = number;
    string num2 = a.number;

    bigint div = bigint(number) / bigint(a.number);
    bigint mod = bigint(number) - div * bigint(a.number);

    return mod.formatNumber();
}


ostream& operator<<(ostream& out, const bigint& a) {
    out << a.number;
    return out;
}

istream& operator>>(istream& in, bigint& a) {
    in >> a.number;
    a.formatNumber();
    return in;
}


bool bigint::operator==(const bigint& a) const {
    return number == a.number;
}

bool bigint::operator!=(const bigint& a) const {
    return number != a.number;
}

bool bigint::operator<(const bigint& a) const {
    if (number.size() != a.number.size()) return number.size() < a.number.size();
    return number < a.number;
}

bool bigint::operator<=(const bigint& a) const {
    return *this < a || *this == a;
}

bool bigint::operator>(const bigint& a) const {
    return !(*this <= a);
}

bool bigint::operator>=(const bigint& a) const {
    return !(*this < a);
}

