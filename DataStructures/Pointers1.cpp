#include <iostream>
using namespace std;
int gv =10;
int fun()
{
int a,b,d;   //local variables to fun
char c;

a = 65;
c = 'C';

int *pa,*pb;
pa = &a;
int **ppa;
ppa= &pa;
d=**ppa;
return d;
}