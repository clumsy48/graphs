
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
#define vc vector<int>
#define vvc vector<vc>
#define pri pair<int, int>

int xking[] = {0, 0, -1, 1, -1, 1, -1, 1};
int yking[] = {1, -1, 0, 0, -1, 1, 1, -1};
int xhorse[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int yhorse[] = {2, 2, 1, 1, -1, -1, -2, -2};

bool checkPointForBoundaryLimits(int x, int n, int y, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

void populateHorseNextPositions(vvc &chess, int n, int m, int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int a = x + xhorse[i];
        int b = y + yhorse[i];
        if (checkPointForBoundaryLimits(a, n, b, m) && chess[a][b] == 0)
        {
            chess[a][b] = 5;
        }
    }
}

bool bfs(pair<int,int> start, pair<int,int> end, vvc &chess, int n, int m)
{
    queue<int> bfsq;
    vector<bool> rvis(m, false);
    vector<vector<bool>> vis(n, rvis);
    vis[start.first][start.second] = true;
    bfsq.push(start.first);
    bfsq.push(start.second);
    bfsq.push(0);
    chess[start.first][start.second]=5;
    int count=0;
    while (!bfsq.empty())
    {
        int ci = bfsq.front();
        bfsq.pop();
        int cj = bfsq.front();
        bfsq.pop();
        int dist = bfsq.front();
        bfsq.pop();
        
        if(ci==end.first && cj==end.second){
            
            cout << "Minimal possible length of a trip is " << dist << endl;
            return true;
        }
        
        for (int i = 0; i < 8; i++)
        {
            int a = ci + xking[i];
            int b = cj + yking[i];
            if (checkPointForBoundaryLimits(a, n, b, m)  && chess[a][b]!=5 )
            {
                bfsq.push(a);
                bfsq.push(b);
                bfsq.push(dist+1);
                vis[a][b] = true;
                chess[a][b] = 5;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vc rows(m, 0);
        vvc chess(n, rows);
        vector<string> matrix;
        pair<int, int> start, end;
        
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            matrix.emplace_back(s);
            for (int j = 0; j < m; ++j)
            {
                if (s[j] == 'Z'){
                     populateHorseNextPositions(chess, n, m, i, j);
                     chess[i][j] = 5;
                }
                else if (s[j] == 'A')
                {
                    chess[i][j] = 1;
                    start.first = i;
                    start.second = j;
                }
                else if (s[j] == 'B')
                {
                    chess[i][j] = 2;
                    end.first = i;
                    end.second = j;
                }
            }
        }
        if(bfs(start, end, chess, n, m)==false){
          cout << "King Peter, you can't go now!\n";   
        }
    }

    return 0;
}
