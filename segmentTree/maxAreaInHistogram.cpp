#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(0)
ll minVal(ll *hist, ll i, ll j) 
{ 
    if (i == -1) return j; 
    if (j == -1) return i; 
    return (hist[i] < hist[j])? i : j; 
}
ll RMQ(ll *hist,ll *st, ll cur, ll ql, ll qr, ll l, ll r)
{
    if (l > qr || r < ql)
        return -1;
    if (l >= ql && r <= qr)
    {
        return st[cur];
    }
    ll m = (l + r) / 2;
    ll leftSeg = RMQ(hist,st, 2 * cur+1 , ql, qr, l, m);
    ll rightSeg = RMQ(hist,st, 2 * cur + 2, ql, qr, m + 1, r);
    
    return minVal(hist,leftSeg,rightSeg);
}
void build(ll *arr, ll *st, ll cur, ll l, ll r)
{
    if (l == r)
    {
        st[cur] = l;
    }
    else
    {
        ll m = (l + r) / 2;
        build(arr, st, 2 * cur + 1, l, m);
        build(arr, st, 2 * cur + 2, m + 1, r);
        st[cur] = minVal(arr,st[2*cur+1],st[2*cur+2]);           
        
    }
}
ll findMaxAreaUtil(ll *hist, ll *st, ll l,ll r,ll n){
    if(l>r) return INT_MIN;
    if(l==r) return hist[l];
    ll m = RMQ(hist,st,0,l,r,0,n-1);
    return max(findMaxAreaUtil(hist,st,l,m-1,n),max(hist[m]*(r-l+1),findMaxAreaUtil(hist,st,m+1,r,n)));
}
ll findMaxArea(ll *hist, ll *st, ll n)
{
    return findMaxAreaUtil(hist,st,0,n-1,n);
}
int main()
{
    while(true){
        ll n;
        cin >> n;
        if(n==0) break;
        ll arr[n];
        ll st[4*n+1];
        //memset(st,-1,sizeof(st));
        for(int i=0;i<n;i++)
        cin >> arr[i];
        build(arr, st, 0, 0, n - 1);
       // for(int i=0;i<4*n;i++)
       // cout << st[i] << " ";
        
       cout << findMaxArea(arr, st, n) << endl;
    }
    
    //cout << RMQ(hist,st,0,2,4,0,n-1) << endl;
    
    return 0;
}
