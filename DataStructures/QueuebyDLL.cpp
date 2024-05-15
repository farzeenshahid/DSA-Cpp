#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
class queue
{
    public:
    void Enqueue(int data);
    void Dequeue();
    bool isEmpty();
    void display();
};
bool queue::isEmpty()
{
    return front == NULL && rear == NULL; 
}

void queue::Enqueue(int x)
{
    struct Node *temp = new Node;
    temp->data=x;
    temp->next=NULL;
    if(isEmpty())
    {
        front = rear = temp;
        return;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    
}
void queue::Dequeue()
{
    struct Node *temp = front;
    if(isEmpty())
    {
        cout<<"Queue is empty!"<<endl;
    }
    else if(front==rear)
    {
        front = rear =NULL;
    }
    else
    {
        front=front->next;
    }
    free(temp);

}
void queue::display()
{
    Node *temp;
    temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    queue q;
    q.Enqueue(5);
    q.display();
    q.Enqueue(14);
    q.display();
    q.Enqueue(42);
    q.display();
    q.Enqueue(60);
    q.display();
    q.Enqueue(39);
    q.display();
    q.Enqueue(75);
    q.Dequeue();
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();
}