#include <iostream>
using namespace std;
int bin_search(int low,int high,int x,int arr[])
{
    
    if(low<=high)
    {
        int mid=(low+high)/2;
    
        if (x==arr[mid])
            return mid;
        else if(x>arr[mid])
            return bin_search(mid+1,high,x,arr);
        else if(x<arr[mid]) 
            return bin_search(low,mid-1,x,arr);

    }
    else
        return -1;

}
int main()
{
    int arr[]={2,3,4,5,6,7,8};
    int n= sizeof(arr);
    int x;
    cout<<"Enter no. to search: ";
    cin>>x;
    int result=bin_search(0,n-1,x,arr);
    if (result==-1)
    {
        cout<<x<<" is not present in array.";
    }
    else
        cout<<x<<" is present at position "<<result;
    return 0;
}