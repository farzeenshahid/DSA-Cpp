#include<iostream>
using namespace std;
void bubble_sort(int n)
{
    int i,j ,temp;
    int arr[n];
    cout<<"Enter the "<<n<<" elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the element for ["<<i<<"] position:";
        cin >> arr[i] ;
    }
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j] = temp ;
        }
    }
    cout<<"The sorted array is:";
    for(int x=0;x<n;x++)
        cout<<" "<<arr[x];
    
}
int main()
{
    int n;

    cout<<"Enter the number of element of your array:";
    cin>>n;
    cout<<"\n\n";
    bubble_sort(n);
    
    return 0;
}
