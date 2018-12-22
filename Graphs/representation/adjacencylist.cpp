/***********************************************************************************************
 * 
 * Undirected GRAPH 
 * REPRESENTATION USING VECTOR ARRAY
 * 
 * *******************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> graph[],int src ,int dest){
           graph[src].push_back(dest);
           graph[dest].push_back(src);
}

int main(){

    int vecticesCount ,edgeCount;
    cin >> vecticesCount;

    vector<int> graph[vecticesCount];
    cout << "enter edges count :";
    cin >> edgeCount;
    cout << "enter edges (ex- source_vectex dest_vertex)\n";
    for(int i=0 ; i<edgeCount ;i++){
        int src ,dest;
        cin >> src >> dest;
        addEdge(graph,src,dest);
    }
}
