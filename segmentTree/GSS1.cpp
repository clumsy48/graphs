/**********************************
 * minimum QUERY
 * *****************/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(0)
struct stNode{
  int prefix,suffix,maxsum,sum;  
};

struct stNode getNodeLR(struct stNode *st,struct stNode lc,struct stNode rc){
    struct stNode temp;
     
    temp.prefix = max(lc.prefix,lc.sum+rc.prefix);
    temp.suffix = max(rc.suffix,rc.sum+lc.suffix);
    temp.sum = rc.sum + lc.sum;
    temp.maxsum = max(temp.suffix,max(temp.prefix,max(rc.maxsum,max(max(lc.maxsum,rc.maxsum),lc.suffix+rc.prefix))));
    return temp;
}
struct stNode RMQ(struct stNode *st,ll cur,ll ql,ll qr,ll l,ll r){
    struct stNode temp ;
    temp.prefix = temp.suffix = temp.maxsum = temp.sum =INT_MIN;
    if(l > qr || r < ql) return temp;
    if (l >= ql && r <= qr) {
        return st[cur];
    }
    ll m = (l+r)/2;
    
    struct stNode lst = RMQ(st,2*cur+1,ql,qr,l,m);
    struct stNode rst = RMQ(st,2*cur+2,ql,qr,m+1,r);
    if(lst.sum==INT_MIN) return rst;
    if(rst.sum==INT_MIN) return lst;
     temp = getNodeLR(st,lst,rst);
     return temp;
}

struct stNode getNode(struct stNode *st,int lc,int rc){
    struct stNode temp;
    temp.prefix = max(st[lc].prefix,st[lc].sum+st[rc].prefix);
    temp.suffix = max(st[rc].suffix,st[rc].sum+st[lc].suffix);
    temp.sum = st[rc].sum + st[lc].sum;
    temp.maxsum = max(temp.suffix,max(temp.prefix,max(max(st[lc].maxsum,st[rc].maxsum),st[lc].suffix+st[rc].prefix)));
    return temp;
}
void build(ll *arr,struct stNode *st,ll cur,ll l ,ll r){
    if(l==r){
        st[cur].prefix = arr[l];
        st[cur].suffix = arr[l];
        st[cur].maxsum = arr[l];
        st[cur].sum = arr[l];
    }else{
        ll m= (l+r)/2;
        build(arr,st,2*cur+1,l,m);
        build(arr,st,2*cur+2,m+1,r);
        st[cur] = getNode(st,2*cur+1,2*cur+2);
    }
}

int main()
{
    fastIO;
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    cin >> arr[i];
    struct stNode st[4*n];
    
    build(arr,st,0,0,n-1);
    
   ll q;
   cin >> q;
   while(q--){
       ll x,y;
       cin >> x >>y;
       cout  << RMQ(st,0,x-1,y-1,0,n-1).maxsum << endl;;
   }
  
    
    return 0;
}
