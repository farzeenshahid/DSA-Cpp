#include <iostream>
using namespace std;
class Array
{
    private:
    int *Base;
    public:
    Array(int **table,int X,int Y,int *Base);
    void calculate_address(int x,int y);
};

Array::Array(int **table,int X,int Y,int *Base)
{
    cout<<"Creating a 2D array\n";
    cout<<"Enter no. of rows: "<<X<<endl;
    cout<<"Enter no of columns: "<<Y<<endl;
    for(int x=0;x<X;x++)
    {
        for(int y=0;y<Y;y++)
        {
            cout<<"Enter element at position ["<<x<<"]["<<y<<"] "<<endl;
            cin>>table[x][y];
        }
    }
    Base=&table[0][0];
}
void Array::caclulate_address(int x,int y)
{
    ptr[x][y]=Base+(x*Y+y)*sizeof(int);
    cout<<"Address of "<<arr[x][y]<<" is "<<&arr[x][y]<<endl;
}


void Array::calculate_address()
{
    

}