#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* link;
};
struct Node *Head;   //gloabal variable

class List
{
    public:
    
    int x;
    List()
    {
        Head=NULL;
    }
   /* void Insert(int x,int i)
    {
        Node* temp1 = new Node();

        if (i<n)
        {
            
        }
        
    }*/
    void insert(Node** Head){
        Node *temp = new Node;    //Definition and declaration of new node
        cout<<"Enter value to insert: \n";
        cin>>x;
        temp->data = x;
        temp->link = NULL;
        if(*Head!=NULL)
        {
            temp->link=*Head;
        }
        *Head=temp; 
    }
    void PrintList()
    {
        Node* temp = Head;
        cout<<"List is: ";
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp = temp->link;
        }
        cout<<endl;
    }
};
int main()
{
    List l1;
    int n;
    cout<<"Enter no. of elements you want in list: ";
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        l1.insert(&Head);
        l1.PrintList();
    }
    return 0;
}