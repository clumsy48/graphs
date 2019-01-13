#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void initialize(int arr[], int rank[], int N)
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
        rank[i] = 1;
    }
}

int find(int arr[], int i)
{
    while (arr[i] != i)
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void weighted_union(int arr[],int rank[],int src,int dest){
  int src_root = find(arr,src);
  int dest_root = find(arr,dest);
  if(rank[src_root]>rank[dest_root]){
      arr[src_root] = arr[dest_root];
      rank[src_root]++;
  }else{
      arr[dest_root] = arr[src_root];
      rank[dest_root]++;
  }

}
void addEdge(vector<int> graph[],int src ,int dest){
           graph[src].emplace_back(dest);
           graph[dest].emplace_back(src);
}
bool iscycle(vector<pair<int,int> > egdes,int n ,int e){
      int arr[n],rank[n];
      initialize(arr,rank,n);
      for(int i=0;i<e;i++){
            int xroot = find(arr,egdes[i].first);
            int yroot = find(arr,egdes[i].second);

            if(xroot==yroot){
                return true;
            }else{
                weighted_union(arr,rank,xroot,yroot);
            }
      }
      return false;
}
int main(){
    int v=3,e=3;
    vector<int> graph[v];
    vector<pair<int,int> > egdes;
    egdes.emplace_back(make_pair(0,1));
    egdes.emplace_back(make_pair(1,2));
    egdes.emplace_back(make_pair(0,2));
    
    iscycle(egdes,v,e);
    return 0;
}