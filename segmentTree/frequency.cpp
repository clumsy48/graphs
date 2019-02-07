/**********************************
 * Frequency QUERY
 * *****************/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define ll long long
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0)
struct stNode
{
    ll fqLtMost, fqRtMost, fqMax;
};
struct stNode getNodeFromLRB(int *arr,int m,int l,int r,struct stNode *st, int lc, int rc)
{
    struct stNode temp;
    temp.fqLtMost = st[lc].fqLtMost ;
    if(arr[l]==arr[m+1]) temp.fqLtMost +=st[rc].fqLtMost;
    temp.fqRtMost = st[rc].fqRtMost;
    if(arr[m]==arr[r]) temp.fqRtMost += st[lc].fqRtMost;
    temp.fqMax = max(st[lc].fqMax,st[rc].fqMax);
    if(arr[m]==arr[m+1]) temp.fqMax = max(st[lc].fqRtMost+st[rc].fqLtMost, temp.fqMax);
    
    return temp;
}
struct stNode getNodeFromLR(int *arr,int m,int l,int r,struct stNode *st, struct stNode lc, struct stNode rc)
{
    struct stNode temp;
    temp.fqLtMost = lc.fqLtMost ;
    if(arr[l]==arr[m+1]) temp.fqLtMost += rc.fqLtMost;
    temp.fqRtMost = rc.fqRtMost;
    if(arr[m]==arr[r]) temp.fqRtMost += lc.fqRtMost;
    temp.fqMax = max(lc.fqMax,rc.fqMax);
    if(arr[m]==arr[m+1]) temp.fqMax = max(lc.fqRtMost+rc.fqLtMost, temp.fqMax);
    
    return temp;
}
struct stNode RMQ(int *arr,struct stNode *st, int cur, int ql, int qr, int l, int r)
{
    struct stNode temp;
    temp.fqLtMost = temp.fqRtMost = temp.fqMax = 0;
    if (l > qr || r < ql )
        return temp;
    if (l >= ql && r <= qr)
    {
        return st[cur];
    }
    int m = (l + r) / 2;
    
    struct stNode lst = RMQ(arr,st, 2 * cur + 1, ql, qr, l, m);
    struct stNode rst = RMQ(arr,st, 2 * cur + 2, ql, qr, m + 1, r);

    temp = getNodeFromLR(arr,m,l,r, st, lst, rst);
    return temp;
}


void build(int *arr, struct stNode *st, int cur, int l, int r)
{
    if(l>r)
    return; 
    if (l == r)
    {
        st[cur].fqLtMost = 1;
        st[cur].fqRtMost = 1;
        st[cur].fqMax = 1;
    }
    else
    {
        int m = (l + r) / 2;
        build(arr, st, 2 * cur + 1, l, m);
        build(arr, st, 2 * cur + 2, m + 1, r);
        
        st[cur] = getNodeFromLRB(arr,m,l,r, st, 2 * cur + 1, 2 * cur + 2);
        
    }
}

int main()
{
    fastIO;
    int n,q;
    cin >> n ;
    while(n){
    cin >> q;        
    int arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    struct stNode st[4 * n];

    build(arr, st, 0, 0, n - 1);

    while (q--)
    {
        int x, y;
        cin >> x ;
        if(x==0) break;
        cin >> y;
        cout << RMQ(arr,st, 0, x - 1, y - 1, 0, n - 1).fqMax << endl;
        
    }
    cin >> n;
}
    return 0;
}
