#include <iostream>
using namespace std;
class Array
{
    private:
    int table[10];      //1-D Static Array declaration 
    int *address[10];
    int *Base=&table[0];
    public:
    Array();            //constructor
    void WriteArray();  
    void ReadArray();
    void InsertElement(int element,int index);
    void Calculated_Element_Address(int index);  //manually calculate address of an element in an array
    void display_cmplt_Address();      //manually calculate address of every element in an array
};
Array::Array()
{
    cout<<"Creating an array of size 10\n";
}
void Array::WriteArray()
{
    for(int i=0;i<10;i++)
    {
        cout<<"Enter element at position "<<i+1<<endl;
        cin>>table[i];
    }
}
void Array::ReadArray()
{
    for(int j=0;j<10;j++)
    {
        cout<<table[j]<<" ";
    }
    cout<<"\n";   
}
void Array::InsertElement(int element,int index)
{
    table[index]=element;
}
void Array::display_cmplt_Address()
{
    for(int k=0;k<10;k++)
    {
        address[k]=Base+k*sizeof(int);         //Address of table[i]=Base Address+i*sizeof D.T
        cout<<"Address of element at position "<<k+1<<" is "<<&table[k];
           
    }
}
void Array::Calculated_Element_Address(int index)
{
    
    address[index]=Base+index*sizeof(int);
    cout<<"Address of element at position "<<index+1<<" is "<<&table[index]<<endl;
     
}
int main()
{
    Array table1;
    table1.WriteArray();//input array from user
    table1.ReadArray();//displaying array
    table1.display_cmplt_Address();//displaying address of complete array manually
    table1.Calculated_Element_Address(5); //displaying address of an element in array
    table1.InsertElement(33,4);
    return 0;
}