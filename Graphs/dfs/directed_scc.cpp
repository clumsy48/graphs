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

vector<int> post_order_set;
int fill_ordering = 1;
static int component_counter = 0;

void addEdge(vector<int> graph[], vector<int> *r_graph, int src, int dest)
{
    graph[src].emplace_back(dest);
    r_graph[dest].emplace_back(src);
}
void dfsUtil(vector<int> graph[], int src, vector<bool> &visited)
{
    visited[src] = true;
    for (vector<int>::iterator i = graph[src].begin(); i != graph[src].end(); i++)
    {
        if (visited[*i] == false)
            dfsUtil(graph, *i, visited);
    }

    post_order_set.emplace_back(src);
}
void dfs(vector<int> r_graph[], int src, int verticesCount)
{
    vector<bool> visited(verticesCount, false);

    for (int i = 0; i < verticesCount; i++)
    {
        if (visited[i] == false)
            dfsUtil(r_graph, i, visited);
    }
}
void findSCCUtil(vector<int> graph[], int src, vector<bool> &visited)
{
    visited[src] = true;
    cout << "compnent : " << component_counter << " " << src << endl;
    for (vector<int>::iterator i = graph[src].begin(); i != graph[src].end(); i++)
    {
        if (visited[*i] == false)
            findSCCUtil(graph, *i, visited);
    }
    
}
void findSCC(vector<int> graph[], int verticesCount)
{
    fill_ordering = 0;
    vector<bool> visited(verticesCount, false);
    for (vector<int>::reverse_iterator i = post_order_set.rbegin(); i != post_order_set.rend(); i++)
    {
        if (visited[*i] == false)
        {
            component_counter++;
            findSCCUtil(graph, *i, visited);
            cout << endl;
        }
        
    }
}
int main()
{

    int verticesCount = 10;

    vector<int> graph[verticesCount];
    vector<int> r_graph[verticesCount];

    addEdge(graph, r_graph, 0, 1);
    addEdge(graph, r_graph, 0, 6);
    addEdge(graph, r_graph, 1, 2);
    addEdge(graph, r_graph, 2, 3);
    addEdge(graph, r_graph, 3, 5);
    addEdge(graph, r_graph, 3, 9);
    addEdge(graph, r_graph, 4, 3);
    addEdge(graph, r_graph, 5, 4);
    addEdge(graph, r_graph, 5, 2);
    addEdge(graph, r_graph, 6, 7);
    addEdge(graph, r_graph, 7, 8);
    addEdge(graph, r_graph, 8, 7);
    addEdge(graph, r_graph, 8, 9);

    dfs(r_graph, 0, verticesCount);

    findSCC(graph, verticesCount);
}