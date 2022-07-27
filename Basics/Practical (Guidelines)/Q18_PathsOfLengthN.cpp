#include <iostream>
using namespace std;

int main()
{
    int vertices;
    cout<<"Enter the number of vertices:";
    cin>>vertices;
    cout<<"Enter the graph in form of adjacency matrix:";
    int matrices[vertices][vertices];
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            cin>>matrices[i][j];
        }
    }
    cout<<"Enter the path length:";
    int n;
    cin>>n;
    int src,des;
    cout<<"Enter the source vertex(0>= and<=v-1):";
    cin>>src;
    cout<<"Enter the destination vertex (0>= and<=v-1):";
    cin>>des;
    int mul[vertices][vertices];
    int mu[vertices][vertices];
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
          mu[i][j]=matrices[i][j];  
        }
    }
    for(int h=2;h<=n;h++)
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < vertices; k++)
                mul[i][j] += matrices[i][k]*mu[k][j];
        }
    }
 
    
    for (int i=0; i<vertices; i++)
        for (int j=0; j<vertices; j++)
            matrices[i][j] = mul[i][j];
    
    cout<<"Number of possible paths between source and destination:"<<matrices[src][des];        

    return 0;
}