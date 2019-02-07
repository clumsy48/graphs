/**********************************
 * minimum QUERY
 * *****************/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int RMQ(int *st,int cur,int ql,int qr,int l,int r){
    if(l > qr || r < ql) return INT_MAX;
    if (l >= ql && r <= qr) {
        return st[cur];
    }
    int m = (l+r)/2;
    int leftSeg = RMQ(st,2*cur+1,ql,qr,l,m);
    int rightSeg = RMQ(st,2*cur+2,ql,qr,m+1,r);
    return min(leftSeg,rightSeg);
}
void build(int *arr,int *st,int cur,int l ,int r){
    if(l==r){
        st[cur] = arr[l];
    }else{
        int m= (l+r)/2;
        build(arr,st,2*cur+1,l,m);
        build(arr,st,2*cur+2,m+1,r);
        st[cur] = min(st[2*cur+1],st[2*cur+2]);
    }
}
void update(int st[],int cur,int ind,int value,int l,int r){
    if(l==r){
        st[cur] = value;
    }else{
        int m= (l+r)/2;
        if(ind<=m) update(st,2*cur+1,ind,value,l,m);
        else update(st,2*cur+2,ind,value,m+1,r);
        st[cur] = min(st[2*cur+1],st[2*cur+2]);
    }
}
int main()
{
    int n=4;
    int arr[] = {6,9,7,4};
    int st[4*n];
    build(arr,st,0,0,n-1);
    for(int i=0;i<4*n;i++){
        cout << st[i] << " ";
    }
    arr[2] = 3;
    
    update(st,0,2,arr[2],0,n-1);
    cout << "\nafter update\n";
    for(int i=0;i<4*n;i++){
        cout << st[i] << " ";
    }
    cout << "\nRMQ (2,3) : " << RMQ(st,0,2,3,0,n-1);
    
    return 0;
}
