/**********************************
 * minimum QUERY
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
    int fqLtMost, fqRtMost, fqMax;
};

struct stNode getNodeLR(struct stNode *st, struct stNode lc, struct stNode rc)
{
    struct stNode temp;

    temp.prefix = max(lc.prefix, lc.sum + rc.prefix);
    temp.suffix = max(rc.suffix, rc.sum + lc.suffix);
    temp.sum = rc.sum + lc.sum;
    temp.maxsum = max(temp.suffix, max(temp.prefix, max(rc.maxsum, max(max(lc.maxsum, rc.maxsum), lc.suffix + rc.prefix))));
    return temp;
}
struct stNode RMQ(int *arr,struct stNode *st, ll cur, ll ql, ll qr, ll l, ll r)
{
    struct stNode temp;
    temp.fqLtMost = temp.fqRtMost = temp.fqMax = 0;
    if (l > qr || r < ql)
        return temp;
    if (l >= ql && r <= qr)
    {
        return st[cur];
    }
    ll m = (l + r) / 2;
    if(ql>m) return RMQ(arr,st, 2 * cur + 2, ql, qr, m + 1, r);
    else if(qr<m) return RMQ(arr,st, 2 * cur + 1, ql, qr, l, m);
    struct stNode lst = RMQ(arr,st, 2 * cur + 1, ql, qr, l, m);
    struct stNode rst = RMQ(arr,st, 2 * cur + 2, ql, qr, m + 1, r);
   /* if (lst.fqMax == 0)
        return rst;
    if (rst.fqMax == 0)
        return lst;*/
    temp = getNodeFromLR(arr,m,l,r, st, 2 * cur + 1, 2 * cur + 2);;
    return temp;
}

struct stNode getNodeFromLR(int *arr,int m,int l,int r,struct stNode *st, int lc, int rc)
{
    struct stNode temp;
    temp.fqLtMost = st[lc].fqLtMost ;
    if(arr[l]==arr[m+1]) temp.fqLtMost =+ st[rc].fqLtMost;
    temp.fqRtMost = st[rc].fqRtMost;
    if(arr[m]==arr[r+1]) temp.fqRtMost =+ st[lc].fqRtMost;
    temp.fqMax = max(st[lc].fqMax,st[rc].fqMax);
    if(arr[m]==arr[m+1]) temp.fqMax = max(st[lc].fqRtMost+st[rc].fqLtMost, temp.fqMax);
    
    return temp;
}
void build(int *arr, struct stNode *st, int cur, int l, int r)
{
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
        
        st[cur] = getNodeFromLR(arr,m,l,r, st, 2 * cur + 1, 2 * cur + 2);
        
    }
}

int main()
{
    fastIO;
    int n;
    cin >> n;
    int arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    struct stNode st[4 * n];

    build(arr, st, 0, 0, n - 1);

    int q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << RMQ(arr,st, 0, x - 1, y - 1, 0, n - 1).fqMax << endl;
        ;
    }

    return 0;
}
