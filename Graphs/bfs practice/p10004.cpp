#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define floop(i, e) for (int i = 0; i < e; ++i)
#define itrv(i, a) for (vector<int>::iterator itr = a.begin(); i != a.end(); ++i)

void solve(vvi &graph,int nodes)
{
  vector<bool> visited(nodes,false);
  vi assignedColor(nodes);
  queue<int> bfsq;
  bfsq.push(0);
  assignedColor[0] =1;
  visited[0] = true;
  while(!bfsq.empty()){
      int curInd = bfsq.front();
      bfsq.pop();
      itrv(itr, graph[curInd]){
          if(visited[*itr] == false){
              visited[*itr] = true;
              bfsq.push(*itr);
              assignedColor[*itr] = !assignedColor[curInd];
          }else{
              if(assignedColor[*itr]==assignedColor[curInd]){
                  cout << "NOT BICOLORABLE.\n";
                  return;
              }
          }

      }
  }
  cout << "BICOLORABLE.\n";
}
void adddEdge(vvi &graph, int src, int dest)
{
    graph[src].emplace_back(dest);
    graph[dest].emplace_back(src);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int nodes, edges;
        cin >> nodes;
        if(nodes==0) break;
        cin >> edges;
        vvi graph(nodes);
        floop(i, edges)
        {
            int src, dest;
            cin >> src >> dest;
            adddEdge(graph, src, dest);
        }
        solve(graph,nodes);
    }
    return 0;
}
