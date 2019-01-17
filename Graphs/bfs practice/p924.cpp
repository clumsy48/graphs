#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define floop(i, e) for (int i = 0; i < e; ++i)
#define itrv(i, a) for (vector<int>::iterator itr = a.begin(); i != a.end(); ++i)

void solve(vvi graph, int edges, int src)
{
    int maximum_daily_boom_size=0, first_boom_day=0;
    queue<pair<int, int>> bfsq;
    vector<bool> visited(edges, false);
    bfsq.push(make_pair(src, 0));
    visited[src] = true;
    vector<int> boomcount(edges,0);
    while (!bfsq.empty())
    {
        
        pair<int, int> curVertex = bfsq.front();
       // cout << curVertex.first << " " << curVertex.second << endl;
        bfsq.pop();
        itrv(itr, graph[curVertex.first])
        {
            if (visited[*itr] == false)
            {
                visited[*itr] = true;
              //  cout << "neighbour " << *itr << " ";
                bfsq.push(make_pair(*itr,curVertex.second+1));
                boomcount[curVertex.second+1]++;
                
            }
            
        }
    }
    
    for(int i=0;i<edges;i++){
        if(maximum_daily_boom_size<boomcount[i]){
            maximum_daily_boom_size = boomcount[i];
            first_boom_day = i;
        }
    }
    if(maximum_daily_boom_size == 0){
        cout << "0";
    }else{
        cout << maximum_daily_boom_size << " " << first_boom_day;
    }
    
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int edges, temp_n, ifriend, src, t;
    cin >> edges;
    vvi graph(edges);
    floop(i, edges)
    {
        cin >> temp_n;
        while (temp_n--)
        {
            cin >> ifriend;
            graph[i].emplace_back(ifriend);
        }
    }
    cin >> t;
    
    while (t--)
    {
        cin >> src;
        solve(graph, edges, src);
    }

    return 0;
}
