/********************************
 * TOPOLOGICAL SORT
 * DIRECTED GRAPH
 *  (0, 1); 
    (0, 2); 
    (1, 2); 
    (2, 0); 
    (2, 3); 
    (3, 3);
 * 
 * ***********************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> post_order;


void addEdge(vector<int> graph[], int src, int dest)
{
    graph[src].emplace_back(dest);
}
void dfsUtil(vector<int> graph[], int src, vector<bool> &visited)
{
    visited[src] = true;

    for (vector<int>::iterator i = graph[src].begin(); i != graph[src].end(); i++)
    {
        if (visited[*i] == false)
            dfsUtil(graph, *i, visited);
    }
    post_order.push(src);
}
void dfs(vector<int> graph[], int src, int verticesCount)
{
    vector<bool> visited(verticesCount, false);
   
    dfsUtil(graph, src, visited);
    cout << "-----------\nlinear ordering: \n";
    while(!post_order.empty()){
        cout << post_order.top() << " ";
        post_order.pop(); 
    }
    cout << endl;
}


int main()
{

    int verticesCount = 5, edgeCount = 6;

    vector<int> graph[verticesCount];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 3);

    dfs(graph, 0, verticesCount);
    
}