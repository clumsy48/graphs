/********************************
 * TOPOLOGICAL SORT
 * DIRECTED GRAPH
    0, 1;
     0, 3;
     0, 4;
     1, 2;
     2, 3;
     4, 3;
 * 
 * ***********************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct post_order{
    int vertex;
    int ordering;
};

static int counter = 0;
vector<int> pre_order;
vector<struct post_order> post_order;

bool mycompator(struct post_order l,struct post_order r){
      return l.ordering>r.ordering;
}

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
    post_order[src] = {src,++counter};
}
void dfs(vector<int> graph[], int src, int verticesCount)
{
    vector<bool> visited(verticesCount, false);
    pre_order = vector<int>(verticesCount);
    post_order = vector<struct post_order>(verticesCount);
    dfsUtil(graph, src, visited);
    cout << "-----------\nlinear ordering: \n";
    sort(post_order.begin(),post_order.end(),mycompator);
    for(int i=0;i<post_order.size();i++){
       cout << post_order[i].vertex << " ";
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