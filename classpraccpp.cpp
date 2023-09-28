#include<iostream>
using namespace std;

class Rectangle
{
  private:
    int length;
    int breadth;
  public:

    Rectangle() //default constructor and non parameterized
    {
    length=0;
    breadth=0;
    }

    Rectangle(int l, int b)
    {
    length=l;
    breadth=b;
    }

    int area()
    {
    return length*breadth;
    }

    int perimeter()
    {
    return 2*(length+breadth);
    }

    //methods

    void setlenght(int l)
    {
        length=l;
    }

    void setbreadth(int b)
    {
        breadth=b;
    }

    int getlength()
    {
        return length;
    }

    int getbreadth()
    {
        return breadth;
    }
    
    ~Rectangle() //destructor automatically called when main function ends. memory is cleared
    {
        cout<<"Destructor";
    }

};

int main()
{
    Rectangle r(10,5);

    cout<<"Area"<<r.area()<<endl;
    cout<<"Perimeter"<<r.perimeter()<<endl;



    return 0;
}