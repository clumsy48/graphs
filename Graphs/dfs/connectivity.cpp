/********************************
 * FINDING CONNCTED COMPONENTS
 * UNDIRECTED GRAPH
 *  (0, 1) 
    (0, 3) 
    (1, 2) 
    (2, 3) 
    (4, 5) 
    (4, 6)
    (5, 6)
    (7, 8)
 * 
 * ***********************************/
#include <iostream>
#include <vector>


using namespace std;

static int counter =0;
vector<int> component;

void addEdge(vector<int> graph[], int src, int dest)
{
    graph[src].emplace_back(dest);
}
void dfsUtil(vector<int> graph[], int src, vector<bool> &visited,int c)
{
    visited[src] = true;
    component[src] = c;
   
    for (vector<int>::iterator i = graph[src].begin(); i != graph[src].end(); i++)
    {
        if (visited[*i] == false)
            dfsUtil(graph, *i, visited,c);
    }
}
void dfs(vector<int> graph[], int src, int verticesCount)
{
    vector<bool> visited(verticesCount, false);
    component = vector<int>(verticesCount,-1);
    for (int i = 0; i < verticesCount; i++)
    {
        if (visited[i] == false){
            dfsUtil(graph, i,visited, ++counter);
            }
    }
    for(int i=0;i<verticesCount;i++){
        cout << i << " " << component[i] <<endl;
    }
}

int main()
{

    int verticesCount = 9, edgeCount = 8;

    vector<int> graph[verticesCount];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    addEdge(graph, 7, 8);
    counter = 0;
    dfs(graph, 2, verticesCount);
    
}