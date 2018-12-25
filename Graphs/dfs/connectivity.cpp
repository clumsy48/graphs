/********************************
 * 
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

void addEdge(vector<int> graph[], int src, int dest)
{
    graph[src].emplace_back(dest);
}
void dfsUtil(vector<int> graph[], int src, vector<bool> &visited)
{
    visited[src] = true;
    cout << src << "\n";
    for (vector<int>::iterator i = graph[src].begin(); i != graph[src].end(); i++)
    {
        if (visited[*i] == false)
            dfsUtil(graph, *i, visited);
    }
}
void dfs(vector<int> graph[], int src, int vecticesCount)
{
    vector<bool> visited(vecticesCount, false);
    for (int i = 0; i < vecticesCount; i++)
    {
        if (visited[i] == false)
            dfsUtil(graph, i, visited);
    }
}

int main()
{

    int vecticesCount = 9, edgeCount = 8;

    vector<int> graph[vecticesCount];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    addEdge(graph, 7, 8);

    dfs(graph, 2, vecticesCount);
}