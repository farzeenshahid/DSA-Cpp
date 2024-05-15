#include <iostream>
using namespace std;
struct TreeNode
{
    int data;
    struct TreeNode *left,*right;
};
TreeNode *create(int key)
{
    TreeNode *Newnode = new TreeNode();
    Newnode->data=key;
    Newnode->left=0;
    Newnode->right=0;
    return Newnode;   
}
TreeNode *Insert(TreeNode *root,int val)
{
    if(root==NULL)
    {
        root=create(val);
        return root;        
    }
    else if(val<=root->data)
        root->left=Insert(root->left,val);

    
    else 
        root->right=Insert(root->right,val);
    
    return root;
}
bool Search(TreeNode* root,int val)
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
void preorder(TreeNode* root)
{
    if (root==0)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void Inorder(TreeNode* root)
{
    if (root==0)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(TreeNode* root)
{
    if (root==0)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    TreeNode *root=NULL;   //store address of root node
    root=Insert(root,43); root=Insert(root,54); root=Insert(root,5); root=Insert(root,18);
    root=Insert(root,16); root=Insert(root,69); root=Insert(root,10); root=Insert(root,24);
    int key;
    cout<<"Enter key to be searched\n";
    cin>>key;
    if(Search(root,key)==true)
    {
        cout<<"Found\n";
    }
    else
        cout<<"Not Found\n";
    return 0;

}
