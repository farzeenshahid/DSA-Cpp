#include <iostream>
using namespace std;
int main()
{
    int X,Y,W,x,y,w;
    int S=10;
    int R=100;
    int M=100;
    int arr[S][R][M];
    cout<<"Enter no. of 2-D arrays to be created: ";
    cin>>W;
    cout<<"Enter no.of rows: ";
    cin>>X;
    cout<<"Enter no. of cols: ";
    cin>>Y;
    //Storing elements in row major representation
    for(int w=0;w<W;w++)            //w=0...W-1
    {
        for(int x=0;x<X;x++)        //x=0....X-1
        {
            for(int y=0;y<Y;y++)    //y=0.....Y-1
            {
                cout<<"Enter value at ["<<w<<"]["<<x<<"]["<<y<<"]\n";
                cin>>arr[w][x][y];
            }
        }
    }
    cout<<endl;
    for(int w=0; w<W; w++)
    {
        for(int x=0; x<X; x++)
        {
            for(int y=0; y<Y; y++)
                cout<<arr[w][x][y]<<"  ";
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    int *Base = &arr[0][0][0];   //creating a pointer to base address
    int *ptr[W][X][Y];           //creating a pointer for each element
    cout<<"\nDisplaying address in Row major representation\n";
    cout<<"Enter w: "<<endl;
    cin>>w;
    cout<<"Enter x: "<<endl;
    cin>>x;
    cout<<"Enter y: "<<endl;
    cin>>y;
    int row_slot=w*X*Y+x*Y+y;      //slot formula for 3-d row major
    ptr[w][x][y]=Base+(row_slot)*sizeof(int);
    cout<<"Address of "<<arr[w][x][y]<<" is "<<&arr[w][x][y]<<endl;
    /*for(int w=0;w<W;w++)
    {
        for(int x=0;x<X;x++)
        {
            for(int y=0;y<Y;y++)
            {
                int slot=w*X*Y+x*Y+y;      //slot formula for 3-d row major
                ptr[w][x][y]=Base+(slot)*sizeof(int);
                cout<<"Address of "<<arr[w][x][y]<<" is "<<&arr[w][x][y]<<endl;
            }
        }
    }*/
    //Storing element in Column major
    
    cout<<"Displaying address in Column major representation\n";
    cout<<"Enter w: "<<endl;
    cin>>w;
    cout<<"Enter x: "<<endl;
    cin>>x;
    cout<<"Enter y: "<<endl;
    cin>>y;
    int col_slot=y*W*X+x*W+w;     //slot formula for 3-d column major
    ptr[w][x][y]=Base+col_slot*sizeof(int);
    cout<<"Address of "<<arr[w][x][y]<<" is "<<&arr[w][y][x]<<endl;
 /*   for(int w=0;w<W;w++)
    {    
        for(int y=0;y<Y;y++)
        {
            for(int x=0;x<X;x++)
            {
                int slot=y*W*X+x*W+w;     //slot formula for 3-d column major
                ptr[w][x][y]=Base+slot*sizeof(int);
                cout<<"Address of "<<arr[w][x][y]<<" is "<<&arr[w][y][x]<<endl;
            }
        }
    }*/
    return 0;
}