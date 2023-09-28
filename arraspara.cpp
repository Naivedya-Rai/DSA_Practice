#include <iostream>
using namespace std;

int * fun(int n)
{
    int *p;
    p = new int[n];
    //p = (int *)malloc(n*sizeof(int));

    /*for(int i=0;i<n;i++)
    p[i]=i+1;*/
    
    return (p);

}

int main()
{
    int *a,s=7;
    a = fun(s);

    cout<<a<<endl;

    for(int i=0;i<s;i++)
    a[i]=i+1;

    a[0]=26;
    //cout<<a[3]<<endl;

    for (int i=0;i<s;i++)
    cout<<a[i]<<endl;




    return 0;
} 

//array created in heap and accessed using pointers using dynamic memory allocation