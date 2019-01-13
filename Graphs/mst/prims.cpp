/**********************************************************
 * 
 * Dijkstra's ALgorithm using CPP SET,
 * set in cpp stl manages order minimum is at begin
 * Complexity  O( (V+E) * (log(V) )
 * from source to all vertices
 * no negative weight edge 
 *  
 * ***********************************************************************/

#include <iostream>
#include <set>
#include <vector>
#include <utility>

#define vertexPairItr vector<pair<int, int>>::iterator
#define vertexPair vector<pair<int, int>>
#define dpair pair<int, int>
#define mp(a, b) make_pair(a, b)
#define eb(a) emplace_back(a)

using namespace std;

void addEdge(vertexPair graph[], int src, int dest, int weight)
{
    graph[src].eb(mp(dest, weight));
    graph[dest].eb(mp(src, weight));
}
struct customCmp
{
    bool operator()(const dpair &lhs, const dpair &rhs) const
    {
        return lhs.second < rhs.second;
    }
};
void findshortestPath(vertexPair graph[], int noOfVectices, int src)
{

    set<dpair, customCmp> edgeRelaxser;
    vector<int> dist(noOfVectices, __INT_MAX__);
    vector<int> parent(noOfVectices, __INT_MAX__);
    dist[src] = 0;
    parent[src] = -1;
    edgeRelaxser.insert(mp(src, 0));
    while (!edgeRelaxser.empty())
    {
        dpair minVertexPair = *edgeRelaxser.begin();
        edgeRelaxser.erase(edgeRelaxser.begin());
        int curVertex = minVertexPair.first;
        //  int curWeight = minVertexPair.second;
        for (vertexPairItr i = graph[curVertex].begin(); i != graph[curVertex].end(); i++)
        {
            dpair adjvertexPair = *i;
            parent[(*i).first] = src;
            if (edgeRelaxser.find(*i)!=edgeRelaxser.end() && dist[adjvertexPair.first] > dist[curVertex] + adjvertexPair.second)
            {
                dist[adjvertexPair.first] = dist[curVertex] + adjvertexPair.second;
                edgeRelaxser.insert(mp(adjvertexPair.first, dist[adjvertexPair.first]));
            }
        }
        for(int i=0;i<noOfVectices;i++){
            cout << parent[i] << " " << dist[i] << endl;
        }
    }
    for (int i = 0; i < noOfVectices; i++)
    {
        cout << dist[i] << " ";
    }
    
}
int main(void)
{
    int noOfVectices = 9;
    vertexPair graph[noOfVectices];
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    findshortestPath(graph, noOfVectices, 0);
    return 0;
}