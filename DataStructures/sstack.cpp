#include <iostream>
using namespace std;



int stack[8];
int top = -1;
int PUSH(int data)
{
    if(top<8-1)
    {
    top++;
    stack[top] = data;
    return 0;
    }
    else {return -1;}
}
    
int POP(int *ret)
{
    if(top!= -1) {
    *ret = stack[top];
    top--; 
    return 0;
    }
    else {return -1;}   
}
int *r = POP();

if(POP(&r)!=0)
  {cout<<"UF";}

