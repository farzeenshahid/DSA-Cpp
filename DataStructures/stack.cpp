#include <iostream>
using namespace std;
class stack{
    public:
    int res;
    int ss;
    int sstack[4];
    int top;
    
    stack();
    int isEmpty();
    int isFull();
    int POP();
    void PUSH(int data);
    int display_stack();

};
stack::stack()
{
    ss=4;
    top=-1; 
    
}
int stack::isEmpty()
{
    if(top==-1)
    {
        cout<<"Stack is empty (UF)";
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int stack::isFull()
{
    if(top==ss-1)
    {
        cout<<"Stack is full(OF)";
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int stack::POP()
{
    if(!isEmpty())
    
        return sstack[top--];
    
    
}
void stack::PUSH(int data)
{
    if(!isFull())
    {
        sstack[++top]=data;
    }   
}
int stack::display_stack()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    { 
        for(int i=0;i<ss-1;i++)
        {
            {
                return sstack[i];
                cout<<endl;   
            }    
        }
    }
}
int main()
{
    stack s1;
    
    
    s1.PUSH(42);
    s1.PUSH(49);
    s1.PUSH(49);
    s1.PUSH(45);
    
    //s1.PUSH(21);
    s1.POP();
    s1.display_stack();
    return 0;


}