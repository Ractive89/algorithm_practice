/*
 * @Author: Ractive 
 * @Date: 2019-02-19 23:57:49 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 02:20:25
 */
#ifndef Currency_
#define Currency_

#include "illegalParameterValue.h"

class currency
{
    friend std::ostream &operator<<(std::ostream &, const currency &);
    friend std::istream &operator>>(std::istream &, currency &);
    //友元 赋予别的类与函数访问currency的私有成员
    //BUG1:std::istream输出流 一定不要const
  private:
    long amount;

  public:
    enum signType
    {
        plus,
        minus
    };
    currency(signType the_Sign = plus, unsigned long the_Dollars = 0, unsigned int the_Cents = 0);
    ~currency();

    void set_Value(signType, unsigned long, unsigned int);
    void set_Value(double);
    signType get_Sign() const;
    unsigned long get_Dollars() const;
    unsigned int get_Cents() const;

    currency interest(double ratio, int year) const;
    currency interest_compound(double ratio, int year) const;
    currency add(const currency &) const;
    currency subtract(const currency &) const;
    currency *increment(const currency *other);
    currency *decrement(const currency *other);

    currency *multiply(const currency *other);
    currency *divide(const currency *other);

    currency operator=(const double value) const;
    currency operator=(const int value) const;
    currency operator+(const currency &other) const;
    currency operator-(const currency &other) const;
    currency operator*(const currency &other) const;
    currency operator/(const currency &other) const;

    currency *operator+=(const currency &other);
    currency *operator-=(const currency &other);
    currency *operator*=(const currency &other);
    currency *operator/=(const currency &other);

    void input();
    //void output(std::ostream &) const;
};

currency::currency(signType the_Sign, unsigned long the_Dollars, unsigned int the_Cents)
{
    set_Value(the_Sign, the_Dollars, the_Cents);
}

currency::~currency()
{
}
void currency::set_Value(signType the_Sign, unsigned long the_Dollars, unsigned int the_Cents)
{
    if (the_Cents > 99)
        throw illegalParameterValue("Cents should be <100");
    amount = the_Dollars * 100 + the_Cents;
    if (the_Sign == minus)
        amount = -amount;
}

void currency::set_Value(double the_Amount)
{
    if (the_Amount < 0)
        amount = (long)((the_Amount - 0.001) * 100);
    else
        amount = (long)((the_Amount + 0.001) * 100);
}

currency::signType currency::get_Sign() const
{
    if (amount < 0)
        return minus;
    else
        return plus;
}

unsigned long currency::get_Dollars() const
{
    if (amount < 0)
        return (-amount) / 100;
    else
        return amount / 100;
}

unsigned int currency::get_Cents() const
{
    if (amount < 0)
        return -amount - get_Dollars() * 100;
    else
        return amount - get_Dollars() * 100;
}

currency currency::interest(double ratio, int year) const
{
    currency interest_Amount;
    interest_Amount.amount = this->amount * ratio * year;
    return interest_Amount;
}

currency currency::interest_compound(double ratio, int year) const
{
    currency interest_Compound_Amount;
    long Backup = this->amount;
    int i;
    for (i = 0; i < year; i++)
        Backup = Backup * (1 + ratio);
    interest_Compound_Amount.amount = Backup;
    return interest_Compound_Amount;
}

currency currency::add(const currency &other) const
{
    currency y;
    y.amount = this->amount + other.amount;
    return y;
}

currency currency::subtract(const currency &other) const
{
    currency y;
    y.amount = this->amount - other.amount;
    return y;
}

currency *currency::increment(const currency *other)
{
    this->amount += other->amount;
    return this;
}

currency *currency::decrement(const currency *other)
{
    this->amount -= other->amount;
    return this;
}

currency *currency::multiply(const currency *other)
{
    this->amount *= other->amount;
    return this;
}

currency *currency::divide(const currency *other)
{
    this->amount /= other->amount;
    return this;
}

currency currency::operator=(const double value) const
{
    currency result;
    result.set_Value(value);
    return result;
}

currency currency::operator=(const int value) const
{
    currency result;
    result.amount = value;
    return result;
}

currency currency::operator+(const currency &other) const
{
    currency result;
    result.amount = this->amount + other.amount;
    return result;
}

currency currency::operator-(const currency &other) const
{
    currency result;
    result.amount = this->amount - other.amount;
    return result;
}

currency currency::operator*(const currency &other) const
{
    currency result;
    result.amount = this->amount * other.amount;
    return result;
}

currency currency::operator/(const currency &other) const
{
    currency result;
    result.amount = this->amount / other.amount;
    return result;
}

currency *currency::operator+=(const currency &other)
{
    this->amount += other.amount;
    return this;
}

currency *currency::operator-=(const currency &other)
{
    this->amount -= other.amount;
    return this;
}

currency *currency::operator*=(const currency &other)
{
    this->amount *= other.amount;
    return this;
}

currency *currency::operator/=(const currency &other)
{
    this->amount /= other.amount;
    return this;
}

std::ostream &operator<<(std::ostream &out, const currency &other)
{
    long the_Amount = other.amount;
    if (other.amount < 0)
    {
        out << '-';
        the_Amount = -the_Amount;
    }
    long dollars = the_Amount / 100;
    out << '$' << dollars << '.';
    int cents = the_Amount - dollars * 100;
    if (cents < 10)
        out << '0';
    out << cents;
    return out;
}

std::istream &operator>>(std::istream &in, currency &other)
{
    in >> other.amount;
    if (!in)
        currency();
    return in;
}

void currency::input()
{
    std::cout << "Enter the currency amount as a real number" << std::endl;
    double the_Value;
    std::cin >> the_Value;
    set_Value(the_Value);
}

#endif
