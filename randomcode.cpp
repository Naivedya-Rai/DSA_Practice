#include<iostream>

using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

int main()
{

    rectangle r = {11,8};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    rectangle *k=&r; //assigning address of r to pointer k
    cout<<k->breadth<<endl;
    cout<<k->length<<endl;





    rectangle *p;  //creating a pointer //for c use struct rectangle *p
    p= new rectangle; //creates object of struct rect in heap memory
   //for c = p=(struct rectangle *)malloc(sizeof(struct rectangle)); //cREATING OBJ DYNAMICALLY //allocating space in heep memory
    (*p).length = 10;
    p -> breadth = 5; // assigning values using pointer in heap

    cout<<p->breadth<<endl;
    cout<<(*p).breadth<<endl;

    return 0;
}