#ifndef BIGINTEGER_HPP
#define BIGINTEGER_HPP
#include <algorithm>
#include <exception>
#include <map>
#include <iostream>
#include <string>
class BigInteger
{
private:
    struct BigIntegerFormatError;
    struct RadixNumberOutOfRange;
    struct DivideByZero;
    struct EvenRootOfNegativeNumber;
    static std::map<char, int> radixNumber;
    std::string value;

public:
    BigInteger();
    BigInteger(const BigInteger &other);
    BigInteger(int value);
    BigInteger(unsigned int value);
    BigInteger(long value);
    BigInteger(unsigned long value);
    BigInteger(long long a);
    BigInteger(unsigned long long a);
    BigInteger(const char *value, int radix = 10);
    BigInteger(const std::string value, int radix = 10);
    virtual ~BigInteger();
    std::string toString();
    static void swap(BigInteger &val1, BigInteger &val2);
    static bool checkFormatInteger(const char *str, int radix = 10);
    static bool checkFormatInteger(const std::string str, int radix = 10);
    static BigInteger add(const BigInteger &val1, const BigInteger &val2);
    static BigInteger subtract(const BigInteger &val1, const BigInteger &val2);
    static BigInteger multiply(const BigInteger &val1, const BigInteger &val2);
    static BigInteger divide(const BigInteger &val1, const BigInteger &val2);
    static BigInteger mod(const BigInteger &val1, const BigInteger &val2);
    static BigInteger abs(const BigInteger &val);
    static BigInteger exp(const BigInteger &val1, const BigInteger &val2);
    static BigInteger root(const BigInteger &val1, const BigInteger &val2);
    BigInteger &abs();
    BigInteger &exp(const BigInteger &val);
    BigInteger &root(const BigInteger &val);
    static bool lessthan(const BigInteger &val1, const BigInteger &val2);
    static bool lessequal(const BigInteger &val1, const BigInteger &val2);
    static bool greaterthan(const BigInteger &val1, const BigInteger &val2);
    static bool greaterequal(const BigInteger &val1, const BigInteger &val2);
    static bool equal(const BigInteger &val1, const BigInteger &val2);
    static bool notequal(const BigInteger &val1, const BigInteger &val2);
    static bool isOdd(const BigInteger &val);
    static bool isEven(const BigInteger &val);
    BigInteger &operator++();
    BigInteger operator++(int);
    BigInteger &operator--();
    BigInteger operator--(int);
    BigInteger operator+(const BigInteger &other);
    BigInteger operator-(const BigInteger &other);
    BigInteger operator*(const BigInteger &other);
    BigInteger operator/(const BigInteger &other);
    BigInteger operator%(const BigInteger &other);
    bool operator<(const BigInteger &other);
    bool operator<=(const BigInteger &other);
    bool operator>(const BigInteger &other);
    bool operator>=(const BigInteger &other);
    bool operator==(const BigInteger &other);
    bool operator!=(const BigInteger &other);
    BigInteger operator<<(const BigInteger &other);
    friend std::ostream &operator<<(std::ostream &out, const BigInteger &value);
    BigInteger &operator<<=(const BigInteger &other);
    BigInteger operator>>(const BigInteger &other);
    friend std::istream &operator>>(std::istream &in, BigInteger &value);
    BigInteger &operator>>=(const BigInteger &other);
    BigInteger &operator=(const BigInteger &other);
    BigInteger &operator=(BigInteger &&other);
    BigInteger &operator+=(const BigInteger &other);
    BigInteger &operator-=(const BigInteger &other);
    BigInteger &operator*=(const BigInteger &other);
    BigInteger &operator/=(const BigInteger &other);
    BigInteger &operator%=(const BigInteger &other);
    static std::string castNumbertobase10(std::string str, int radix);
    std::string convertBase(int radix);
};
#endif /* !BIGINTEGER_HPP */
