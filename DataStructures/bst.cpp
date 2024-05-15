#include <iostream>
#include <stdlib.h>
using namespace std;

struct bst_node{
    int data;
    struct bst_node* left;
    struct bst_node* right;
};

bst_node* GetNode(int item)
{
    bst_node* new_node=(struct bst_node* )malloc(sizeof(struct bst_node));
    new_node->data=item;
    new_node->left=0;
    new_node->right=0;
    return new_node;
}

bst_node* Insert(bst_node* root, int val)
{
    if (root==0) //empty
        root=GetNode(val);
    else if (val<=root->data)
        root->left=Insert(root->left,val);
    else
        root->right=Insert(root->right,val);
    return root;
}

bool Search(bst_node* root,int val)
{
    if (root==0)
        return false;
    else if (root->data==val) //if key is equal to root
        return true;
    else if (val<=root->data) // if key is less than root
        return Search(root->left,val);
    else // if key is greater than root
        return Search(root->right,val);
}

void preorder(struct bst_node* root)
{
    if (root==0)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void Inorder(struct bst_node* root)
{
    if (root==0)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(struct bst_node* root)
{
    if (root==0)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int Smallest(struct bst_node* root)
{
    struct bst_node* current=root;
    while(current->left!=0)
        current=current->left;
    return (current->data);
}

int largest(struct bst_node* root)
{
    struct bst_node* current=root;
    while(current->right!=0)
        current=current->right;
    return (current->data);
}

bst_node* Smallest_Delete(struct bst_node* root)
{
    struct bst_node* current=root;
    while(current->left!=0)
        current=current->left;
    return (current);
}
bst_node* Delete_node(struct bst_node* root,int key)
{
    if (root==0)
        return root;
    if(key<root->data)
        root->left=Delete_node(root->left,key);
    else if (key>root->data)
        root->right=Delete_node(root->right,key);
    else //node with at most one child
    {
        if(root->left==0)
        {
            struct bst_node* temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==0)
        {
            struct bst_node* temp=root->left;
            free(root);
            return temp;
        }
        //node with two children
        struct bst_node* temp;
        temp=Smallest_Delete(root->right);
        root->data=temp->data;
        root->right=Delete_node(root->right,temp->data);

    }
    return root;
}

int count(bst_node* node)
{
    int c=1;
    if(node==0)
        return 0;
    else
    {
        c+=count(node->left);
        c+=count(node->right);
        return c;
    }
}

int findMax(int a, int b)
{
  if(a>=b)
    return a;
  else
    return b;
}

int Height(bst_node* root)
{
  if(root==0)
    return 0;
  return findMax(Height(root->left),Height(root->right))+1;
}

int count_internal(bst_node* root)
{
    int c=1;
    if (root!=0)
    {
        count_internal(root->left);
        if(root->left!=0 || root->right!=0)
            c++;
        count_internal(root->right);
    }
    return c;
}

int count_external(struct bst_node* root)
{
    if(root==0)
        return 0;
    if(root->left==0 && root->right==0)
        return 1;
    else
        return (count_external(root->left)+count_external(root->right));
}

int main ()
{
    bst_node* root;
    root=0;
    int value[20];
    int i,s;
    int choice,del;
    do{
        cout<<endl<<"Enter 1 for Insert element."<<endl;
        cout<<"Enter 2 for Preorder Traversal."<<endl;
        cout<<"Enter 3 for Inorder Traversal."<<endl;
        cout<<"Enter 4 for Postorder Traversal."<<endl;
        cout<<"Enter 5 for Smallest Element."<<endl;
        cout<<"Enter 6 for Largest Element."<<endl;
        cout<<"Enter 7 for Delete an item."<<endl;
        cout<<"Enter 8 for count total number of nodes."<<endl;
        cout<<"Enter 9 for count number of External nodes."<<endl;
        cout<<"Enter 10 for count number of Internal nodes."<<endl;
        cout<<"Enter 11 for height of tree."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the values: ";
                cin>>i;
                root=Insert(root,i);
                break;
            case 2:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                {
                    cout<<"Preorder Reversal: ";
                    preorder(root);
                    cout<<endl;
                }
                break;
            case 3:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                {
                    cout<<"Inorder Traversal: ";
                    Inorder(root);
                    cout<<endl;
                }
                break;
            case 4:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                {
                    cout<<"Postorder Reversal: ";
                    Postorder(root);
                    cout<<endl;
                }
                break;
            case 5:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                    cout<<"Smallest element: "<<Smallest(root)<<endl;
                break;
            case 6:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                    cout<<"Largest element: "<<largest(root)<<endl;
                break;
            case 7:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                {
                    cout<<"Enter the value to delete: ";
                    cin>>del;
                    root=Delete_node(root,del);
                    cout<<endl;
                }
                break;
            case 8:
                cout<<"Total number of nodes: "<<count(root)<<endl;
                break;
            case 9:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                    cout<<"External Nodes: "<<count_external(root)<<endl;
                break;
            case 10:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                    cout<<"Internal Nodes: "<<count_internal(root)<<endl;
                break;
            case 11:
                if (root==0)
                    cout<<"Empty Tree."<<endl;
                else
                    cout<<"Height of the tree: "<<Height(root)<<endl;
                break;
            default:
                return 0;
            }
    }while (choice<12);
    return 0;
}




