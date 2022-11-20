﻿#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define WITHD 27

class Fraction
{
    int integer;
    int numerator;
    int denominator;
public:
    int get_integer()const
    {
        return integer;
    }
    int get_numerator()const
    {
        return numerator;
    }
    int get_denominator()const
    {
        return denominator;
    }

    void set_integer(int integer)
    {
        this->integer = integer;
    }
    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denominator(int denominator)
    {
        if (denominator == 0)denominator = 1;
        this->denominator = denominator;
    }

    //         Constructors
    Fraction()
    {
        this->integer = 0;
        this->numerator = 0;
        this->denominator = 1;
        cout.width(WITHD);
        cout <<std::left<< "DefaultConstructor:" << this << endl;
    }

    Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
        cout.width(WITHD);
        cout << std::left << "SingleArgumentsConstructor:" << this << endl;
    }

    Fraction(int numerator, int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        set_denominator(denominator);
        cout.width(WITHD);
        cout << std::left << "Constructor:" << this << endl;

    }

    Fraction(int integer, int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        set_denominator(denominator);
        cout.width(WITHD);
        cout << std::left << "Constructor:" << this << endl;
    }
    ~Fraction()
    {
        cout.width(WITHD);
        cout << std::left << "Destructor:" << this << endl;
    }

    //         Methods:
    void to_proper() //перевод дроби из неправильной в правильную
    {
        integer += numerator / denominator;
        numerator %= denominator;
    }
    void to_improper() //перевод дроби из правильной в неправильную
    {
        numerator += integer * denominator;
        integer = 0;

    }

    void print()const
    {
        if (integer)cout << integer << " ";
        if (numerator)
        {
            cout << numerator << "/" << denominator;
        }
        else if (integer == 0) cout << 0;
        cout << endl;
    }
};

//#define CONSTRUCTORS_CHECK

void main()
{
    setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
    Fraction A;     //конструктор по умолчанию
    A.print();

    Fraction B = 5;      //Single-argument constructor
    B.print();

    Fraction C;
    C.print();

    Fraction D(2, 3, 4);
    D.print();

    D.to_improper();
    D.print();

    D.to_proper();
    D.print();
#endif // CONSTRUCTORS_CHECK


    Fraction A(2, 3, 4);
    Fraction B(3, 4, 5);
    Fraction C = A * B;
    C.print();


}
