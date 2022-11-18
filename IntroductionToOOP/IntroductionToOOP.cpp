#include <iostream>
using namespace std;

class Point
{
    double x;
    double y;
public:
    double get_x()const
    {
        return x;
    }
    double get_y()const
    {
        return y;
    }
    void set_x(double x)
    {
        this->x = x;
    }
    void set_y(double y)
    {
        this->y=y;
    }
    //  Constructor
    /*Point()
    {
        x = y = double(); //Значение по умолчанию для double
        cout << "Constructor:\t" << this << endl;
    }
    Point(double x)
    {
        this->x = x;
        this->y = 0;
        cout << "1argConstructor:\t" << this << endl;

    }*/
    Point(double x=0, double y=0)
    {
        this->x = x;
        this->y = y;
        cout << "Constructor:\t" << this << endl;

    }

    Point(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        cout << "CopyConstructor:\t" << this << endl;
    }

    ~Point ()
    {
        cout << "Destructor:\t" << this << endl;
    }
    //  Method:

    double distance(Point other)
    {
        double x_distance = this->x - other.x;
        double y_distance = this->y - other.y;
        double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
        return distance;
    }

    void print()const
    {
        cout<<"X= "<<x<< "\tY = "<<y<<endl;
    }
};

double distance(Point A, Point B)
{
    double x_distance = A.get_x() - B.get_x();
    double y_distance = A.get_y() - B.get_y();
    double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
    return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK

void main()
{
    setlocale(LC_ALL, "rus");
#ifdef STRUCT_POINT
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
    Point A;
    A.set_x(2);
    A.set_y(3);
    cout << A.get_x() << "\t" << A.get_y() << endl;

    Point B;
    B.set_x(7);
    B.set_y(8);
    cout << "Расстояние от точки 'A' до точки 'B': \t" << A.distance(B) << endl;
    cout << "Расстояние от точки 'B' до точки 'A': \t" << B.distance(A) << endl;

    cout << "расстояние между точками А и В: \t" << distance(A, B) << endl;
    cout << "расстояние между точками B и A: \t" << distance(B, A) << endl;
#endif //#define DISTANCE_CHECK

#ifdef CONSTRUCTOR_CHECK
    Point A;        //Default constructor
    A.print();

    Point B = 5;    //Single-argument constractor
    B.print();

    Point C(8);    //Single-argument constractor
    C.print();

    Point D(5, 8); //Parameted 
    D.print();

    Point E = D;
    E.print(); //CopyConstructor
#endif //#define CONSTRUCTOR_CHECK
}

