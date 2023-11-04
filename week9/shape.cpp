/*Create a base class called shape. Use this class to store two double type values that
could be used to compute the area of figures. Derive two classes called triangle and
rectangle from shape. Add to the base class, a member function get_data() to
initialize base class data members and another member function display_area() to
compute and display the area of figures. Make display_area() as a virtual function
and re-define this function in the derived classes to suit their requirements. Using
these three classes, design a program that will accept dimensions of a triangle of a
rectangle interactively, and display the area. (Hint: The two input values can be
treated ad lengths of two sides for rectangle and as base and height for triangle) */
#include<iostream>
using namespace std;
class Shape
{
protected:
        double len1, len2;
public:
        virtual void getdata(){
        cin>>len1>>len2;
        }
        virtual void display_area() = 0;
};

class Triangle : public Shape
{
public:
        void getdata()
        {
                cout<<"\nEnter base and height of triangle: ";
                Shape::getdata();
        }
        void display_area()
        {
                cout<<"\nArea: "<<(0.5*len1*len2);
       }
};

class Rectangle : public Shape
{
public:
        void getdata()
        {
                cout<<"\nEnter length and breadth of rectangle: ";
                Shape::getdata();
        }
        void display_area()
        {
                cout<<"\nArea: "<<len1*len2;
        }
};

int main()
{
        Shape* bptr;
        Triangle t;
        Rectangle r;

        bptr=&t;
        bptr->getdata();
        bptr->display_area();


        bptr=&r;
        bptr->getdata();
        bptr->display_area();
        return 0;
}






