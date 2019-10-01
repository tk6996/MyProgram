#include "BigInteger.hpp"
using namespace std;
struct BigInteger::BigIntegerFormatError : exception
{
    const char *what() const noexcept override
    {
        return "BigInteger::BigIntegerFormatError";
    }
};
struct BigInteger::RadixNumberOutOfRange : exception
{
    const char *what() const noexcept override
    {
        return "BigInteger::RadixNumberOutOfRange";
    }
};
struct BigInteger::DivideByZero : exception
{
    const char *what() const noexcept override
    {
        return "BigInteger::DivideByZero";
    }
};
struct BigInteger::EvenRootOfNegativeNumber : exception
{
    const char *what() const noexcept override
    {
        return "BigInteger::EvenRootOfNegativeNumber";
    }
};
map<char, int> BigInteger::radixNumber = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}, {'Q', 26}, {'R', 27}, {'S', 28}, {'T', 29}, {'U', 30}, {'V', 31}, {'W', 32}, {'X', 33}, {'Y', 34}, {'Z', 35}, {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}, {'g', 16}, {'h', 17}, {'i', 18}, {'j', 19}, {'k', 20}, {'l', 21}, {'m', 22}, {'n', 23}, {'o', 24}, {'p', 25}, {'q', 26}, {'r', 27}, {'s', 28}, {'t', 29}, {'u', 30}, {'v', 31}, {'w', 32}, {'x', 33}, {'y', 34}, {'z', 35}};
BigInteger::BigInteger()
{
    this->value = "0";
}
BigInteger::BigInteger(const BigInteger &other) : BigInteger(other.value)
{
}
BigInteger::BigInteger(int value)
{
    this->value = to_string(value);
}
BigInteger::BigInteger(unsigned int value)
{
    this->value = to_string(value);
}
BigInteger::BigInteger(long value)
{
    this->value = to_string(value);
}
BigInteger::BigInteger(unsigned long value)
{
    this->value = to_string(value);
}
BigInteger::BigInteger(long long value)
{
    this->value = to_string(value);
}
BigInteger::BigInteger(unsigned long long value)
{
    this->value = to_string(value);
}
BigInteger::BigInteger(const char *value, int radix) : BigInteger(string(value), radix)
{
}
BigInteger::BigInteger(const string value, int radix)
{
    this->value = castNumbertobase10(value, radix);
    if (this->value == "-0")
        this->abs();
}

BigInteger::~BigInteger()
{
}

string BigInteger::toString()
{
    return value;
}
void BigInteger::swap(BigInteger &val1, BigInteger &val2)
{
    string temp = val1.value;
    val1.value = val2.value;
    val2.value = temp;
}
bool BigInteger::checkFormatInteger(const char *str, int radix)
{
    return checkFormatInteger(string(str), radix);
}
bool BigInteger::checkFormatInteger(string str, int radix)
{
    if (radix < 2 || radix > 36)
        throw RadixNumberOutOfRange();
    if (str.front() == '-')
        str = str.substr(1);
    for (auto &&chr : str)
        if (radixNumber.find(chr) == radixNumber.end() || radixNumber[chr] >= radix)
            return false;
    return true;
}
BigInteger BigInteger::add(const BigInteger &val1, const BigInteger &val2)
{
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num1.value.front() == '-' ^ num2.value.front() == '-')
    {
        if (num1.value.front() == '-')
        {
            num1.abs();
            return subtract(num2, num1);
        }
        else
        {
            num2.abs();
            return subtract(num1, num2);
        }
    }
    else
    {
        bool minus = false;
        if (num1.value.front() == '-')
        {
            minus = true;
            num1.abs();
            num2.abs();
        }
        string sum;
        int curry = 0;
        while (!(num1.value.empty()) || !(num2.value.empty()) || curry)
        {
            int v1 = 0, v2 = 0;
            if (!num1.value.empty())
            {
                v1 = num1.value.back() - '0';
                num1.value.pop_back();
            }
            if (!num2.value.empty())
            {
                v2 = num2.value.back() - '0';
                num2.value.pop_back();
            }
            int digit = v1 + v2 + curry;
            curry = digit / 10;
            sum.push_back((digit % 10) + '0');
        }
        if (minus)
            sum.push_back('-');
        reverse(sum.begin(), sum.end());
        return BigInteger(sum);
    }
}
BigInteger BigInteger::subtract(const BigInteger &val1, const BigInteger &val2)
{
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num1.value.front() == '-' ^ num2.value.front() == '-')
    {
        if (num1.value.front() == '-')
        {
            num2.value = '-' + num2.value;
            return add(num1, num2);
        }
        else
        {
            num2.abs();
            return add(num1, num2);
        }
    }
    else
    {
        bool minus = false, _swap = false;
        if (num1.value.front() == '-')
        {
            minus = true;
            num1.abs();
            num2.abs();
        }
        if (num1 < num2)
            _swap = true;
        if (_swap)
        {
            swap(num1, num2);
            minus = !minus;
        }
        string dif;
        int curry = 0;
        while (!(num1.value.empty()) || !(num2.value.empty()))
        {
            int v1 = 0, v2 = 0;
            if (!num1.value.empty())
            {
                v1 = num1.value.back() - '0';
                num1.value.pop_back();
            }
            if (!num2.value.empty())
            {
                v2 = num2.value.back() - '0';
                num2.value.pop_back();
            }
            int digit = v1 - v2 + curry;
            curry = digit < 0 ? -1 : 0;
            if (curry)
                digit += 10;
            dif.push_back((digit % 10) + '0');
        }
        while (dif.length() > 1)
        {
            if (dif.back() == '0')
                dif.pop_back();
            else
                break;
        }
        if (minus)
            dif.push_back('-');
        reverse(dif.begin(), dif.end());
        return BigInteger(dif);
    }
}
BigInteger BigInteger::multiply(const BigInteger &val1, const BigInteger &val2)
{
    bool minus = false;
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num1 == 0 || num2 == 0)
        return BigInteger();
    if (num1.value.front() == '-')
    {
        num1.abs();
        minus = !minus;
    }
    if (num2.value.front() == '-')
    {
        num2.abs();
        minus = !minus;
    }
    reverse(num1.value.begin(), num1.value.end());
    reverse(num2.value.begin(), num2.value.end());
    vector<int> multiplier(num1.value.length() + num2.value.length(), 0);
    for (int i = 0; i < num2.value.length(); i++)
    {
        for (int j = 0; j < num1.value.length(); j++)
            multiplier[i + j] += ((num1.value[j] - '0') * (num2.value[i] - '0'));
    }
    for (int ind = 0; ind < multiplier.size(); ind++)
    {
        if (ind + 1 < multiplier.size())
            multiplier[ind + 1] += multiplier[ind] / 10;
        multiplier[ind] %= 10;
    }
    while (multiplier.size() > 1)
    {
        if (multiplier.back())
            break;
        multiplier.pop_back();
    }
    string multi;
    for (auto &&digit : multiplier)
        multi.push_back(digit + '0');
    if (minus)
        multi.push_back('-');
    reverse(multi.begin(), multi.end());
    return BigInteger(multi);
}
BigInteger BigInteger::divide(const BigInteger &val1, const BigInteger &val2)
{
    bool minus = false;
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num2 == 0)
        throw DivideByZero();
    if (num1.value.front() == '-')
    {
        num1.abs();
        minus = !minus;
    }
    if (num2.value.front() == '-')
    {
        num2.abs();
        minus = !minus;
    }
    BigInteger dividend;
    string quotient;
    for (auto &&digit : num1.value)
    {
        dividend = (dividend * 10) + BigInteger(digit - '0');
        int qd = 0;
        while (dividend >= num2)
        {
            dividend -= num2;
            qd++;
        }
        quotient.push_back(qd + '0');
    }
    int row = 0;
    while (row < quotient.length() - 1)
    {
        if (quotient[row] != '0')
            break;
        row++;
    }
    quotient = quotient.substr(row);
    if (minus)
        quotient = '-' + quotient;
    return BigInteger(quotient);
}
BigInteger BigInteger::mod(const BigInteger &val1, const BigInteger &val2)
{
    bool minus = false;
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num2 == 0)
        throw DivideByZero();
    if (num1.value.front() == '-')
    {
        num1.abs();
        minus = !minus;
    }
    if (num2.value.front() == '-')
    {
        num2.abs();
        minus = !minus;
    }
    BigInteger remainder;
    string mod;
    for (auto &&digit : num1.value)
    {
        remainder = (remainder * 10) + BigInteger(digit - '0');
        int qd = 0;
        while (remainder >= num2)
        {
            remainder -= num2;
            qd++;
        }
    }
    return BigInteger(minus ? -1 : 1) * remainder;
}
BigInteger BigInteger::abs(const BigInteger &val)
{
    BigInteger temp = val;
    if (temp.value.front() == '-')
        temp.value = temp.value.substr(1);
    return temp;
}
BigInteger BigInteger::exp(const BigInteger &val1, const BigInteger &val2)
{
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    BigInteger power = 1;
    if (num2 > 0)
    {
        BigInteger p = exp(num1, num2 / 2);
        power = p * p * (isOdd(num2) ? num1 : 1);
    }
    else if (num2 < 0)
        return 0;
    return power;
}
BigInteger BigInteger::root(const BigInteger &val1, const BigInteger &val2)
{
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    BigInteger root = 1;
    if (num1 < 0 && BigInteger::isEven(num2))
        throw EvenRootOfNegativeNumber();
    if (num1 == 0)
        return 0;
    if (num2 > 0)
    {
        BigInteger kvalue;
        do
        {
            kvalue = root;
            root = (((num2 - 1) * kvalue) + (num1 / exp(kvalue, num2 - 1))) / num2;
        } while (abs(kvalue - root) > 0);
    }
    else if (num2 < 0)
        return 0;
    else
        throw DivideByZero();
    return root;
}
BigInteger &BigInteger::abs()
{
    this->value = abs(*this).value;
    return *this;
}

BigInteger &BigInteger::exp(const BigInteger &val)
{
    this->value = exp(*this, val).value;
    return *this;
}
BigInteger &BigInteger::root(const BigInteger &val)
{
    this->value = root(*this, val).value;
    return *this;
}
bool BigInteger::lessthan(const BigInteger &val1, const BigInteger &val2)
{
    if (val1.value.front() == '-' ^ val2.value.front() == '-')
    {
        if (val1.value.front() == '-')
            return true;
        else
            return false;
    }
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num1.value.front() == '-')
        swap(num1.abs(), num2.abs());
    if (num1.value.length() < num2.value.length())
        return true;
    else if (num1.value.length() == num2.value.length() && num1.value.compare(num2.value) < 0)
        return true;
    else
        return false;
}
bool BigInteger::lessequal(const BigInteger &val1, const BigInteger &val2)
{
    if (val1.value.front() == '-' ^ val2.value.front() == '-')
    {
        if (val1.value.front() == '-')
            return true;
        else
            return false;
    }
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num1.value.front() == '-')
        swap(num1.abs(), num2.abs());
    if (num1.value.length() < num2.value.length())
        return true;
    else if (num1.value.length() == num2.value.length() && num1.value.compare(num2.value) <= 0)
        return true;
    else
        return false;
}
bool BigInteger::greaterthan(const BigInteger &val1, const BigInteger &val2)
{
    if (val1.value.front() == '-' ^ val2.value.front() == '-')
    {
        if (val1.value.front() == '-')
            return false;
        else
            return true;
    }
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num1.value.front() == '-')
        swap(num1.abs(), num2.abs());
    if (num1.value.length() > num2.value.length())
        return true;
    else if (num1.value.length() == num2.value.length() && num1.value.compare(num2.value) > 0)
        return true;
    else
        return false;
}
bool BigInteger::greaterequal(const BigInteger &val1, const BigInteger &val2)
{
    if (val1.value.front() == '-' ^ val2.value.front() == '-')
    {
        if (val1.value.front() == '-')
            return false;
        else
            return true;
    }
    BigInteger num1 = val1;
    BigInteger num2 = val2;
    if (num1.value.front() == '-')
        swap(num1.abs(), num2.abs());
    if (num1.value.length() > num2.value.length())
        return true;
    else if (num1.value.length() == num2.value.length() && num1.value.compare(num2.value) >= 0)
        return true;
    else
        return false;
}
bool BigInteger::equal(const BigInteger &val1, const BigInteger &val2)
{
    if (val1.value.length() == val2.value.length() && val1.value.compare(val2.value) == 0)
        return true;
    else
        return false;
}
bool BigInteger::notequal(const BigInteger &val1, const BigInteger &val2)
{
    return !equal(val1, val2);
}
bool BigInteger::isOdd(const BigInteger &val)
{
    return ((val.value.back() - '0') % 2);
}
bool BigInteger::isEven(const BigInteger &val)
{
    return !((val.value.back() - '0') % 2);
}
BigInteger &BigInteger::operator++()
{
    return *this += 1;
}
BigInteger BigInteger::operator++(int)
{
    BigInteger result(*this);
    ++(*this);
    return result;
}
BigInteger &BigInteger::operator--()
{
    return *this -= 1;
}
BigInteger BigInteger::operator--(int)
{
    BigInteger result(*this);
    --(*this);
    return result;
}
BigInteger BigInteger::operator+(const BigInteger &other)
{
    return add(*this, other);
}

BigInteger BigInteger::operator-(const BigInteger &other)
{
    return subtract(*this, other);
}

BigInteger BigInteger::operator*(const BigInteger &other)
{
    return multiply(*this, other);
}

BigInteger BigInteger::operator/(const BigInteger &other)
{
    return divide(*this, other);
}

BigInteger BigInteger::operator%(const BigInteger &other)
{
    return mod(*this, other);
}
bool BigInteger::operator<(const BigInteger &other)
{
    return lessthan(*this, other);
}
bool BigInteger::operator<=(const BigInteger &other)
{
    return lessequal(*this, other);
}
bool BigInteger::operator>(const BigInteger &other)
{
    return greaterthan(*this, other);
}
bool BigInteger::operator>=(const BigInteger &other)
{
    return greaterequal(*this, other);
}
bool BigInteger::operator==(const BigInteger &other)
{
    return equal(*this, other);
}
bool BigInteger::operator!=(const BigInteger &other)
{
    return notequal(*this, other);
}
BigInteger BigInteger::operator<<(const BigInteger &other)
{
    return *this * BigInteger(2).exp(other);
}
ostream &operator<<(std::ostream &out, const BigInteger &value)
{
    return out << value.value;
}
BigInteger &BigInteger::operator<<=(const BigInteger &other)
{
    return *this = *this << other;
}
BigInteger BigInteger::operator>>(const BigInteger &other)
{
    return *this / BigInteger(2).exp(other);
}
istream &operator>>(std::istream &in, BigInteger &value)
{
    string input;
    in >> input;
    value = BigInteger(input);
    return in;
}
BigInteger &BigInteger::operator>>=(const BigInteger &other)
{
    return *this = *this >> other;
}
BigInteger &BigInteger::operator=(const BigInteger &other)
{
    if (this != &other)
        this->value = other.value;
    return *this;
}
BigInteger &BigInteger::operator=(BigInteger &&other)
{
    if (this != &other)
        this->value = other.value;
    return *this;
}
BigInteger &BigInteger::operator+=(const BigInteger &other)
{
    return *this = *this + other;
}
BigInteger &BigInteger::operator-=(const BigInteger &other)
{
    return *this = *this - other;
}
BigInteger &BigInteger::operator*=(const BigInteger &other)
{
    return *this = *this * other;
}
BigInteger &BigInteger::operator/=(const BigInteger &other)
{
    return *this = *this / other;
}
BigInteger &BigInteger::operator%=(const BigInteger &other)
{
    return *this = *this % other;
}
string BigInteger::castNumbertobase10(string number, int radix)
{
    if (!checkFormatInteger(number, radix))
        throw BigIntegerFormatError();
    bool minus = false;
    if (number.front() == '-')
    {
        number = number.substr(1);
        minus = true;
    }
    int index;
    for (index = 0; index < number.length() - 1; index++)
        if (number[index] != '0')
            break;
    number = number.substr(index);
    BigInteger base10;
    if (radix != 10)
    {
        reverse(number.begin(), number.end());
        for (int i = number.length() - 1; i >= 0; i--)
        {
            BigInteger value = 1;
            for (int j = 0; j < i; j++)
                value *= radix;
            base10 += (BigInteger(radixNumber[number[i]]) * value);
        }
    }
    else
        base10.value = number;
    if (minus && base10 != 0)
        base10.value.insert(base10.value.begin(), '-');
    return base10.value;
}
string BigInteger::convertBase(int radix)
{
    if (radix < 2 || radix > 36)
        throw RadixNumberOutOfRange();
    else if (radix == 10)
        return this->value;
    else
    {
        static const string digits = "0123456789ABCDEFGHIJKLMNOPQRSUVWXYZ";
        string result;
        char **end = NULL;
        BigInteger temp;
        bool minus = false;
        if (value.front() == '-')
        {
            minus = true;
        }
        temp = BigInteger::abs(*this);
        while (temp > 0)
        {
            result.push_back(digits[strtol((temp % radix).value.c_str(), end, 10)]);
            temp /= radix;
        }
        if (minus)
            result.push_back('-');
        reverse(result.begin(), result.end());
        return result;
    }
}
