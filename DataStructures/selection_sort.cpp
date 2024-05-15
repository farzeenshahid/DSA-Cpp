#include <iostream>
using namespace std;
void selection_sort(int n)
{
	int temp,s[n];
    cout<<"Enter the "<<n<<" elements:"<<endl;
    for(int i=0;i<=n-1;i++)
	{
        cout<<"Enter the element for ["<<i<<"] position:";
		cin>>s[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{     //swapping
			if(s[i]>s[j])
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
    cout<<"After sorting"<<endl;
	for(int i=0;i<=n-1;i++)
	    cout<<s[i]<<" ";
}
int main()
{
    int n;
    cout<<"Enter the number of elements:";
	cin>>n;
    selection_sort(n);
    return 0;
}