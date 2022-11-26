#include <iostream>
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

    void reduce()   //Сокращение дробей
    {
        int k = 0;
        
        for (int i = 999; i > 1; i--)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;
                k++;
            }
        }
        if (k == 0)
        {
            cout << "Дробь не сокращаемая." << endl;
        }
        else
        {
            cout << "Дробь после сокращения: "; 
            print();
        }

    }
    //перегрузка арифметических операторов:
    Fraction operator + (Fraction &T) {return Fraction (this->integer + T.integer, this->numerator + T.numerator, this->denominator + T.denominator);}
    Fraction operator - (Fraction &T) {return Fraction (this->integer - T.integer, this->numerator - T.numerator, this->denominator - T.denominator);}
    Fraction operator * (Fraction &T) {return Fraction (this->integer * T.integer, this->numerator * T.numerator, this->denominator * T.denominator);}
    Fraction operator / (Fraction &T) {return Fraction (this->integer / T.integer, this->numerator / T.numerator, this->denominator / T.denominator);}

    //перегрузка операторов инкремент/декремент
    Fraction& operator ++ () //префиксный
    {
        ++integer, ++numerator, ++denominator;
        return *this;
    } 
    Fraction& operator -- () //префиксный
    {
        --integer, --numerator, --denominator;
        return *this;
    }
    
    /* ПОСТФИКСНЫЙ НЕ РАБОТАЕТ (я не понял как его сделать для объекта с несколькими полями)
    Fraction operator ++ (int) //постфиксный
    {
        integer++, numerator++, denominator++;
        return *this;
    }
     Fraction operator -- (int) //постфиксный
    {
        integer --, numerator--, denominator--;
        return *this;
    }*/

    //перегрузка оператора присваивания
    Fraction& operator = (const Fraction& fraction)
    {
        integer = fraction.integer;
        numerator = fraction.numerator;
        denominator = fraction.denominator;
        return *this;
    }
    
    //перегрузка операторов составного присваивания
    Fraction& operator += (Fraction& fraction)
    {
        integer += fraction.integer;
        numerator += fraction.numerator;
        denominator += fraction.denominator;
        return *this;
    }
    
    Fraction& operator -= (Fraction& fraction)
    {
        integer -= fraction.integer;
        numerator -= fraction.numerator;
        denominator -= fraction.denominator;
        return *this;
    }

    Fraction& operator *= (Fraction& fraction)
    {
        integer *= fraction.integer;
        numerator *= fraction.numerator;
        denominator *= fraction.denominator;
        return *this;
    }

    Fraction& operator /= (Fraction& fraction)
    {
        integer /= fraction.integer;
        numerator /= fraction.numerator;
        denominator /= fraction.denominator;
        return *this;
    }

    //перегрузка операторов сравнения
    bool operator == (const Fraction& fraction)
    {
        return (this->integer == fraction.integer && this->numerator == fraction.numerator && this->denominator == fraction.denominator);
    }

    bool operator != (const Fraction& fraction)
    {
        return (this->integer != fraction.integer || this->numerator != fraction.numerator || this->denominator != fraction.denominator);
    }

    bool operator > (const Fraction& fraction)
    {
        return (this->integer > fraction.integer && this->numerator > fraction.numerator && this->denominator > fraction.denominator);
    }

    bool operator < (const Fraction& fraction)
    {
        return (this->integer < fraction.integer && this->numerator < fraction.numerator && this->denominator < fraction.denominator);
    }

    bool operator >= (const Fraction& fraction)
    {
        return (this->integer >= fraction.integer && this->numerator >= fraction.numerator && this->denominator >= fraction.denominator);
    }

    bool operator <= (const Fraction& fraction)
    {
        return (this->integer <= fraction.integer && this->numerator <= fraction.numerator && this->denominator <= fraction.denominator);
    }

};

//#define CONSTRUCTORS_CHECK

int main()
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
    Fraction D(2, 1, 2);
    Fraction C = A + B;
    Fraction S = A * D;
    cout << "Object C = " << "\t";
    C.print();
    cout << "Object S = " << "\t";
    S.print();
    cout << "Object D = " << "\t";
    D.print();
    cout << "Object C = " << "\t";
    --C;
    C.print();
    cout << "Object C = " << "\t";
    C = S;
    C.print();
    cout << "Object D = " << "\t";
    D += S;
    D.print();

    if (C == S) cout<<"yes"<<endl;
    if (D != S) cout << "yes" << endl;
    if (D > S) cout << "yes" << endl;
    if (C <= S) cout << "yes" << endl;

    Fraction F(5, 26, 36);  //Проверочный код для метода "void reduce()"
    F.print();
    F.reduce();
    F.print();
}
