#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

struct edge
{
	int src, dest, weight;
};
struct
{
	bool operator()(const edge &lhs, const edge &rhs) const
	{
		return lhs.weight < rhs.weight;
	}
} customCmp;

void initializedisjointSetDS(vector<int> &parent,vector<int> &rank ,int N){
       for(int i=0;i<N;++i){
              parent[i] = i;
              rank[i] = -1;
       }
}
void makeUnion(vector<int> &cycleParent ,vector<int> &rank, int first , int second){
   cycleParent[first] = second;
   if(rank[first]>rank[second]){
	   cycleParent[second] = first;
	   rank[first]+=rank[second];
   }else{
	   cycleParent[first] = second;
	   rank[second]+=rank[first];
   }
}
int findParent(vector<int> cycleParent , int target){
	while(cycleParent[target]!=target){
		cycleParent[target] = cycleParent[cycleParent[target]];
		target = cycleParent[target];
	}
	return target;
}
void mstkruskal(vector<edge> edgeList, int N)
{
	sort(edgeList.begin(), edgeList.end(), customCmp);
	set<int> mst;
	int countEdgeinMSt = 1, curInd = 0;
    vector<int> cycleParent(N);
	vector<int> rank(N);
	initializedisjointSetDS(cycleParent,rank,N);
	while (countEdgeinMSt < N)
	{
		int v1 = findParent(cycleParent,edgeList[curInd].src);
		int v2 = findParent(cycleParent,edgeList[curInd].dest);
		if (v1!=v2)
		{
			mst.insert(v1);
			mst.insert(v2);
			makeUnion(cycleParent,rank,v1,v2);
			countEdgeinMSt++;
			cout << edgeList[curInd].src<< " "<<edgeList[curInd].dest<<" "<< edgeList[curInd].weight << endl;
		}
		curInd++;
	}

}
struct edge getEdge(int src, int dest, int weight)
{
	struct edge newEdge;
	newEdge.src = src;
	newEdge.dest = dest;
	newEdge.weight = weight;

	return newEdge;
}
int main(void)
{
	int noOfVectices = 9;
	vector<edge> edgeList;
	edgeList.emplace_back(getEdge(0, 1, 4));
	edgeList.emplace_back(getEdge(0, 7, 8));
	edgeList.emplace_back(getEdge(1, 2, 8));
	edgeList.emplace_back(getEdge(1, 7, 11));
	edgeList.emplace_back(getEdge(2, 3, 7));
	edgeList.emplace_back(getEdge(2, 8, 2));
	edgeList.emplace_back(getEdge(2, 5, 4));
	edgeList.emplace_back(getEdge(3, 4, 9));
	edgeList.emplace_back(getEdge(3, 5, 14));
	edgeList.emplace_back(getEdge(4, 5, 10));
	edgeList.emplace_back(getEdge(5, 6, 2));
	edgeList.emplace_back(getEdge(6, 7, 1));
	edgeList.emplace_back(getEdge(6, 8, 6));
	edgeList.emplace_back(getEdge(7, 8, 7));

	mstkruskal(edgeList, noOfVectices);
	return 0;
}