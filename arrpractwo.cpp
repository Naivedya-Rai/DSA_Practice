#include <iostream>
using namespace std;

void fun(int *A, int n)
{
    for (int i=0;i<n;i++)
    cout<<A[i]<<endl;
    A[0]=15;

}

int main()
{
    int A[]= {1,2,3,4,5};
    int n=5;
    fun(A,n);

    for (int x:A)
    cout<<x<<" ";

    return 0;
}