#include <iostream>
using namespace std;
int main()
{
    int X,Y;
    int R=100;   //No.of rows
    int M=100;   //No.of cols
    int arr[R][M];
              
    cout<<"Enter no.of rows: ";
    cin>>X;
    cout<<"Enter no. of cols: ";
    cin>>Y;
    //Storing element in Row Major
    for (int x=0;x<X;x++)
    {
        for(int y=0;y<Y;y++)
        {
            cout<<"Enter value for ["<<x<<"]["<<y<<"]\n";
            cin>>arr[x][y];
        }
    }
    cout<<endl;
    for(int x=0; x<X; x++)
        {
            for(int y=0; y<Y; y++)
                cout<<arr[x][y]<<"  ";
            cout<<endl;
        }
        cout<<endl;
    int *Base = &arr[0][0];   //creating a pointer to base address
    int *ptr[X][Y];          //creating a pointer for each element
    cout<<"\nDisplaying address in Row major representation\n";
    for(int x=0;x<X;x++)
    {
        for(int y=0;y<Y;y++)
        {
            ptr[x][y]=Base+(x*Y+y)*sizeof(int);
            cout<<"Address of "<<arr[x][y]<<" is "<<ptr[x][y]<<endl;
        }
    }
    //Storing element in Column major
    
    cout<<endl;
    for(int j=0;j<Y;j++)
    {
        for(int i=0;i<X;i++)
        {
            arr[i][j]=arr[i][j];
        }
    }
    for(int y=0; y<Y; y++)
        {
            for(int x=0; x<X; x++)
                cout<<arr[x][y]<<"  ";
            cout<<endl;
        }
        cout<<endl;
    cout<<"Displaying address in Column major representation\n";
    for(int y=0;y<Y;y++)
    {
        for(int x=0;x<X;x++)
        {
            ptr[x][y]=Base+(y*X+x)*sizeof(int);
            cout<<"Address of "<<arr[x][y]<<" is "<<ptr[y][x]<<endl;
        }
    }
    return 0;

}