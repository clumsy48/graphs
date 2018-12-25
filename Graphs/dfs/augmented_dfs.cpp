#include <iostream>
#include <vector>

using namespace std;

static int counter = 0;
vector<int> pre_order;
vector<int> post_order;


struct Node
{
    int vertex;
    int pre_order;
    int postorder;
};
void addEdge(vector<Node> graph[], int src, int dest)
{
    Node node = {dest, -1, -1};
    graph[src].emplace_back(node);
}
void dfsUtil(vector<Node> graph[], int src, vector<bool> &visited)
{
    visited[src] = true;
    pre_order[src] = ++counter;
    cout << src << " " << counter << "\n";
    for (vector<Node>::iterator i = graph[src].begin(); i != graph[src].end(); i++)
    {
        if (visited[(*i).vertex] == false)
            dfsUtil(graph, (*i).vertex, visited);
    }
    post_order[src] = ++counter;
}
void dfs(vector<Node> graph[], int src, int verticesCount)
{
    vector<bool> visited(verticesCount, false);
    pre_order = vector<int>(verticesCount, -1);
    post_order = vector<int>(verticesCount, -1);
    dfsUtil(graph, src, visited);
    cout << "-------------------\npreorder postorder]: \n";
    for (int i = 0; i < verticesCount; i++)
    {
        cout << i << " " << pre_order[i] << " " << post_order[i] << endl;
        ;
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

    int verticesCount = 4, edgeCount = 6;

    vector<Node> graph[verticesCount];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    dfs(graph, 2, verticesCount);
       
}