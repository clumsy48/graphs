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
/********************************
 * 
 * DIRECTED GRAPH
 *  (0, 1); 
    (0, 2); 
    (1, 2); 
    (2, 0); 
    (2, 3); 
    (3, 3);
 * 
 * ***********************************/

int main()
{

    int vecticesCount = 4, edgeCount = 6;

    vector<int> graph[vecticesCount];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    dfs(graph, 2, vecticesCount);
}