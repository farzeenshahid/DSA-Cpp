#include<iostream>
using namespace std;
void insertion_sort(int n)
{
    int i,j ,temp;
    int arr[n];
    cout<<"Enter the "<<n<<" elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the element for ["<<i<<"] position:";
        cin >> arr[i] ;
    }
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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
    insertion_sort(n);
    return 0;
}
