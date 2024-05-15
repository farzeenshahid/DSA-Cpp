#include<iostream>

using namespace std;

class Queue
{
    public:
    int head, tail;
    int queue_array[10];
    bool isEmpty()
    {
        return head == -1 && tail== -1;
    }
    bool isFull()
    {
        return head == 10-1;
    }

    Queue()
    {
        head = -1;
        tail = -1;
    }

    void enqueue(int x)
    {
        if(isFull())
        {
            cout << "Queue is Full!" << endl;
        }
        else if(isEmpty())
        {
            head=0;
            tail=0;
            
            queue_array[tail]=x;
        }
        else
        {
            tail++;
            queue_array[tail]=x;
        }
            
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else if(tail == head)
        {
            cout<<"Removed item: "<<queue_array[head]<<endl;
            tail = head = -1;
        }
        else
        {
            cout<<"Removed item: "<<queue_array[head]<<endl;
            head++;
        }
    }

    void display()
    {
        if(!isEmpty())
        {
            cout<<"Queue is: "<<endl;
            for(int i=head;i<=tail;i++)
                cout << queue_array[i] << " ";
            cout << endl;
        }
        else
            cout << "Queue is Empty!" << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.display();
    q.enqueue(14);
    q.display();
    q.enqueue(42);
    q.display();
    q.enqueue(60);
    q.display();
    q.enqueue(39);
    q.display();
    q.enqueue(75);
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
}