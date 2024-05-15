#include <iostream>
using namespace std;
int main(){
    int k;  
//initializing array with size(15) for name of employees in a software house
string employees[5];
//storing names of employee in an static array
for(int i=0; i<5; i++)
{
    cout<<"Enter Name of employee "<<i+1;
    cin>>employees[i];
}
//displaying names 
for(int j=0;j<5;j++)
{
    cout<<employees[j]<<" ";
}
//insert/change elements of array
cout<<"Changing name of 3rd person"<<endl;
cin>>employees[3];
cout<<"Changing name of user choice person"<<endl;
cout<<"Enter your choice: "<<endl;
cin>>k;
//displaying array again
cin>>employees[k-1];
for(int j=0;j<5;j++)
{
    cout<<employees[j]<<" ";
}

/*
//initialization and declaration
double salary[5]={50000,45000,22000,10000,35000};
*/
return 0;
}