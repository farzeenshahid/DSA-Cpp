#include <iostream>
using namespace std;
//call by value
/*void swap(int a,int b)
{
    int c;
    c=a; //container (c) <-- value in (a) 
    a=b; //container (a) <-- value in (b)
    b=c; //container (b) <-- value in (c)
    cout<<"Swapped result is "<<a<<" , " <<b<<endl;
}
int main(void)
{
    int x = 5;
    int y = 6;
    swap(x,y);
    return 0;
}
*/
//call by pointers
void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
    cout<<"Swapped result is "<<*a<< ","<<*b<<endl;
}
int main(void)
{
    int x=5;
    int y=6;
    swap(&x,&y);
    return 0;
}
//call by reference
void swap(int &a,int&b)
{
    int c;
    c=a;
    a=b;
    b=c;

}