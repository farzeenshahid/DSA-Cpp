#include <iostream>
using namespace std;
class Graph
{
    public:
        int nVertex;
        int nEdges;
        int **Adj_Matrix;
        Graph()
        {
            cout<<"Enter no. of vertices and edges: ";
            cin>>nVertex>>nEdges;
            Adj_Matrix=new int* [nVertex];
            for(int i=0;i<nVertex;i++)
            {
                Adj_Matrix[i]= new int [nVertex];
            }
            for(int i=0;i<nVertex;i++)
                for(int j=0;j<nVertex;j++)
                {
                    Adj_Matrix[i][j]=0;
                }
        }
        void insert_vertex(string u)
        {
            int newV=nVertex+1;
            for(int i=nVertex;i<newV;i++)
            {
                for(int j=nVertex;j<newV;j++)
                {
                    Adj_Matrix[i][j]=0;
                }
            }
        }
     /*   int getindex(string name)
        {
            for(int i=0;i<nVertex;i++)
            {
                if name==
            }
             

        }
     */      
};