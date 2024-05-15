//Copyright (C) Suresh Kumar Srivastava - All Rights Reserved
//DSA Masterclass courses are available on CourseGalaxy.com

//UndirectedGraph.cpp : Program for undirected graph using adjacency matrix.

#include<iostream>
#include<string>
using namespace std;

static const int maxSize = 30;

class Vertex
{
	public:
		string name;

	public:
		Vertex(string name)
		{
			this->name = name;
		}
};//End of class Vertex

class UndirectedGraph
{
	private:
		int nVertices;
		int nEdges;
		int adj[maxSize][maxSize];
		Vertex *vertexList[maxSize];

	private:
		int getIndex(string vertexName);

	public:
		UndirectedGraph();
		~UndirectedGraph();
		void insertVertex(string vertexName);
		void insertEdge(string source, string destination);
		void deleteEdge(string source, string destination);
		void display();
		

};//End of class UndirectedGraph

UndirectedGraph::UndirectedGraph()
{
	nVertices = 0;
	nEdges = 0;

	for(int i=0; i<maxSize; i++)
	{
		for(int j=0; j<maxSize; j++)
		{
			adj[i][j] = 0;
		}
	}
}//End of UndirectedGraph()

UndirectedGraph::~UndirectedGraph()
{
	for(int i=0; i<nVertices; i++)
	{
		delete vertexList[i];
	}
}//End of ~UndirectedGraph()

void UndirectedGraph::insertVertex(string vertexName)
{
	vertexList[nVertices++] = new Vertex(vertexName);
}//End of insertVertex()
int UndirectedGraph::getIndex(string vertexName)
{
	for( int i = 0; i < nVertices; i++ )
	{
        if (vertexName == vertexList[i]->name)
            return i;
        else 
            return -1;
	}
}
void UndirectedGraph::insertEdge(string source, string destination)
{
	int u = getIndex(source);
	int v = getIndex(destination);
            
	if(u == v)
		cout<< "Not a valid edge\n";
	else if(adj[u][v] != 0)
		cout << "Edge already present\n";
	else  
	{
		adj[u][v] = 1;
		adj[v][u] = 1;
		nEdges++;
	}
}//End of insertEdge()

void UndirectedGraph::deleteEdge(string source, string destination)
{
	int u = getIndex(source);
	int v = getIndex(destination);

	if(adj[u][v] != 0)
	{
		adj[u][v] = 0;
		adj[v][u] = 0;
		nEdges--;
	}
	else
		cout << "Edge does not exist\n";
}//End of deleteEdge()

void UndirectedGraph::display()
{
    for(int i=0; i<nVertices; i++)
    {
     	for(int j=0; j<nVertices; j++)
			cout << adj[i][j] << " ";
        cout <<"\n";
    }
}//End of display()



int main()
{
	UndirectedGraph uGraph;
    //Creating the graph, inserting the vertices and edges
    uGraph.insertVertex("0");
    uGraph.insertVertex("1");
    uGraph.insertVertex("2");
    uGraph.insertVertex("3");

    uGraph.insertEdge("0","3");
    uGraph.insertEdge("1","2");
    uGraph.insertEdge("2","3");
    uGraph.insertEdge("3","1");
    uGraph.insertEdge("0","2");

    //Display the graph
    uGraph.display();
    cout << "\n";

    //Deleting an edge
    uGraph.deleteEdge("0","2");

    //Display the graph
    uGraph.display();

return 0;

}
