#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

#define vs vector<string>
#define mvs unordered_map<string, vs>
#define floop(i, e) for (int i = 0; i < e; ++i)

void printVector(vector<string> v)
{
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int solve(mvs &graph, set<string> &nodes, string src, string dest)
{
    unordered_map<string, bool> visited;
    for (auto &x : nodes)
    {
        visited[x] = false;
    }
    queue<pair<string, int>> bfsq;
    bfsq.push(make_pair(src, 0));
    visited[src] = true;
    while (!bfsq.empty())
    {
        pair<string, int> curInd = bfsq.front();
        bfsq.pop();
       // cout << curInd.first << " " << curInd.second << endl;
        if(curInd.first==dest)
        return curInd.second;
        for (auto &x : graph[curInd.first])
        {
          //  cout << "neighbour " << x << endl;
            if(visited[x]==false){
                visited[x] = true;
                bfsq.push(make_pair(x, curInd.second+1));
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int turn = t;
    cout << "SHIPPING ROUTES OUTPUT\n\n";
    while (turn--)
    {
        cout << "DATA SET  " << t-turn << "\n\n";
        int nodes_count, edges_count, ship_reqs;
        cin >> nodes_count >> edges_count >> ship_reqs;
        set<string> nodes;
        mvs graph;
        vs cols;
        floop(i, nodes_count)
        {
            string temp_node;
            cin >> temp_node;
            nodes.insert(temp_node);
            graph[temp_node] = cols;
        }
        floop(i, edges_count)
        {
            string src, dest;
            cin >> src >> dest;
            graph[src].emplace_back(dest);
            graph[dest].emplace_back(src);
        }
        floop(i, ship_reqs)
        {
            int ship_size;
            string src, dest;
            cin >> ship_size >> src >> dest;
            
            int legs = solve(graph, nodes, src, dest);
            if(legs!=0)
            cout << "$" << ship_size*legs*100 << endl;
            else cout << "NO SHIPMENT POSSIBLE" << endl;
        }
        /*for (auto &itr : graph)
        {
            cout << itr.first << " ";
            printVector(itr.second);
        }*/
        cout << endl;
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
