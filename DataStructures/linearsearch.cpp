#include <iostream>
using namespace std;
int lin_Search(int array[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    
        if (array[i]==key)
            return i;   
    return -1;
}
int main()
{
    int array[]={1,2,3,4,5,6};
    int n= sizeof(array);
    int key = 5;
    int result=lin_Search(array,n,key);
    if(result==-1)
        cout<<"\nNot found.";
    else
        cout<<"Element found at: "<<result;
    return 0;
}