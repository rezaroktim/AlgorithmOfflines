#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define NULL_VALUE -999999
#define INFINITY 999999

using namespace std;

class Graph
{
	int nVertices, nEdges ;
	bool directed ;

public:
	Graph(bool dir = false);
	~Graph();
	int ** matrix ;
	//int dist[nVertices][nVertices];
	void setnVertices(int n);
	void addEdge(int u, int v,int w);
	void writeToFile( int x[]);
    int printSolution(int dist[], int n);
    void printGraph();
    bool floydwarshall();

};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ;

}
void Graph::setnVertices(int n)
{
	this->nVertices = n ;

    matrix = new int*[nVertices];
    for(int i=1;i<=nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=1;j<=nVertices;j++){
            if(i==j)
                matrix[i][j]=0;
            else
                matrix[i][j]=INFINITY;


            }
    }

}

void Graph::addEdge(int u, int v,int w)
{
    matrix[u][v]=w;
}

bool Graph::floydwarshall()
   {

   int dist[nVertices][nVertices];
    int i,j,k;

      for (i = 1; i <= nVertices; i++) {
        for (j = 1; j <= nVertices; j++) {
            dist[i][j] = matrix[i][j];
        }
      }
    for (k = 1; k <= nVertices; k++)
    {
        for (i = 1; i <= nVertices; i++)
        {

            for (j = 1; j <= nVertices; j++)
            {

                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

   //ofstream outputFile;
   // outputFile.open("output.txt");
   // outputFile << "Vertex   Distance from Source\n";
       for(int i=1;i<=nVertices;i++)
    {
        if(dist[i][i]<0) return true;
    }
    cout << "All pair Shortest Paths : \n";
       for (int i = 1; i <= nVertices; i++)
    {
        for (int j = 1; j <= nVertices; j++)
        {
            if (dist[i][j] == INFINITY)
                printf("%7s", "INF");
              // outputFile <<' '<<  "\t" << "INF";

            else
                printf ("%7d", dist[i][j]);
        }
        cout<<endl;
    }
   // outputFile<<i<<' '<<' '<<' '<<"\t"<<dist[i][j]<<endl;*/

  // cout<<"SUCCESSFUL!!!"<<endl;
    //outputFile.close();

    //else cout << "No Negative Cycle !" <<endl;
    return false;

}


Graph::~Graph()
{
    nVertices=0;
    nEdges=0;
    delete[] matrix;

}

int main(void)
{
    int n;
    int s[50];
    Graph g;
    bool x;

    while(1)
    {
        printf("1.File Read. \n");
        printf("2.Floyd-Warshall  3. Exit. \n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
                ifstream file("floyd1.txt");
    if(!file)
    {
                cout<<"Error opening output file"<<endl;

                return -1;
    }
            int u, v,x,p,q,r;
            string line;
            while(getline(file, line))
    {

        stringstream  lineStream(line);

        int value,i=0;

        while(lineStream >> value)
        {

                 s[i]=value;

                 i++;

        }
        n=i;


        cout<<endl;
        cout<<endl;

    }
        int ver=s[0];
        g.setnVertices(ver);
        for(int i=2;i<n;i++)
        {
            if(i%3==2)
            {
                 p=s[i];
                continue;
            }
            if(i%3==0)
            {
                 q=s[i];
                continue;
            }
            if(i%3==1)
            {
                 r=s[i];
                g.addEdge(p,q,r);
            }
        }
  cout<<"File Read Completed!!!"<<endl;
        }
        if(ch==2)
        {
            x=g.floydwarshall();
            if(x) cout << "Negative Cycle Exists !!"<<endl;
            else cout << "No Negative Cycle !!" <<endl;

        }
        else if(ch==3)
        {
            break;
        }
    }

}

