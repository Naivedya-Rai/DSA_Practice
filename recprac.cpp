#include <stdio.h>
#include <iostream>
using namespace std;




int foo (int n, int sum)

{

int k = 0, j = 0;

if (n == 0) return sum;

k = n % 10;

j = n/10;

sum = sum + k;

foo (j, sum);

printf("%d", k);

}

int main ()

{

int a = 2048, sum = 0;

foo (a, sum);

printf("%d\n", sum);

}