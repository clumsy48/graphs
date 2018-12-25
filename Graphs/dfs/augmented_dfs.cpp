/********************************
 * DIRECTED GRAPH
     0, 1
     0, 2
     2, 2
     2, 0
     2, 3
     3, 3
 * 
 * ***********************************/

#include <iostream>
#include <vector>

using namespace std;

static int counter = 0;
vector<int> pre_order;
vector<int> post_order;

void addEdge(vector<int> graph[], int src, int dest)
{
    graph[src].emplace_back(dest);
}
void dfsUtil(vector<int> graph[], int src, vector<bool> &visited)
{
    visited[src] = true;
    pre_order[src] = ++counter;
    cout << src << " " << counter << "\n";
    for (vector<int>::iterator i = graph[src].begin(); i != graph[src].end(); i++)
    {   
        if (visited[*i] == false)
            dfsUtil(graph, *i, visited);
    }
    post_order[src] = ++counter;
}
void dfs(vector<int> graph[], int src, int verticesCount)
{
    vector<bool> visited(verticesCount, false);
    pre_order = vector<int>(verticesCount, -1);
    post_order = vector<int>(verticesCount, -1);
    dfsUtil(graph, src, visited);
    cout << "-------------------\npreorder postorder]: \n";
    for (int i = 0; i < verticesCount; i++)
    {
        cout << i << " " << pre_order[i] << " " << post_order[i] << endl;
        
    }
}


int main()
{

    int verticesCount = 4, edgeCount = 6;

    vector<int> graph[verticesCount];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    dfs(graph, 2, verticesCount);
    
}