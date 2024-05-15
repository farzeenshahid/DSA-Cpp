#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* top=NULL;
int PUSH(int x,struct Node **stack)
{
    Node *temp = new Node;
    temp->data=x;
    temp->next=*stack;
    *stack=temp;
}
void POP()
{
    Node *temp;
    if(top==NULL)
    {
        return;
    }
    else
    {
        temp=top;
        top=top->next;
        free(temp);
    }
    
}
