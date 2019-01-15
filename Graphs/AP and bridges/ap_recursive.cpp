#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> graph[], int src, int dest)
{
    graph[src].emplace_back(dest);
    graph[dest].emplace_back(src);
}
void dfs(vector<int> graph[], vector<bool> &isVisited, vector<int> &parent, vector<int> &time, vector<int> &low, int ctime, int cind, int n)
{
    isVisited[cind] = true;
    time[cind] = ctime+1;
    low[cind] = ctime+1;
    int children = 0;
    for (vector<int>::iterator itr = graph[cind].begin(); itr != graph[cind].end(); ++itr)
    {
        if (isVisited[*itr] == false)
        {
            children++;
            parent[*itr] = cind;
            dfs(graph, isVisited, parent, time, low, ctime+1, *itr, n);
            low[cind] = min(low[cind],low[*itr]);
            if(parent[cind]==-1 && children>1){
                cout << cind << endl;
            }
            if(parent[cind]!=-1 && low[*itr]>=time[cind]){
                cout << cind << endl;
            }

        }
        else if(parent[cind]!=(*itr))
        {
            low[cind] = min(low[cind],time[*itr]);
        }
    }
}
void findAPs(vector<int> graph[], int n)
{
    vector<bool> isVisited(n, false);
    vector<int> parent(n, -1);
    vector<int> time(n, false);
    vector<int> low(n, false);
    parent[0] = -1;
    dfs(graph, isVisited, parent, time, low, 0, 0, n);
    //for()
}
int main()
{

    int vecticesCount = 6, edgeCount = 7;

    vector<int> graph[vecticesCount];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    findAPs(graph, vecticesCount);
}
