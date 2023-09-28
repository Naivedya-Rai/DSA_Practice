#include<iostream>
using namespace std;

class Arithematic
{
    private:
     int a;
     int b;
    public:
     Arithematic(int a, int b);
     int add();
     int sub();
};

Arithematic::Arithematic(int a, int b)
{
    this->a=a;
    this->b=b;

}
int Arithematic::add()
{
    int c;
    c=a+b;
    return c;

}
int Arithematic::sub()
{
    int c;
    c=a-b;
    return c;

}

int main()
{
    Arithematic r(1,5);
}