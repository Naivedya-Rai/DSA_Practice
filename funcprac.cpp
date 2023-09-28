#include <iostream>
using namespace std;

int add(int a, int b)  //created function
{
    int c;
    c = a + b;

    return c;
}

int main() //main function
{
    int x,y,z;
    x=10;
    y=5;

    z = add(x,y); //passing values to the function

    cout<<"value of the addition is: "<<z;




    return 0;
}

