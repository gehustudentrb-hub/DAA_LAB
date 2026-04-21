#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int dest,vector<int>adj[],vector<int>&visited){
    if(node==dest){
        return true;
    }
    visited[node]=1;
    for(auto adjNode: adj[node]){
        if(!visited[adjNode]){
            if(dfs(adjNode,dest,adj,visited)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    vector<int>adj[V];
    cout<<"Enter Edges:";
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source,dest;
    cout<<"Enter source and destination:";
    cin>>source>>dest;
    vector<int>visited(V,0);
    if(dfs(source,dest,adj,visited)){
        cout<<"Path exists"<<endl;
    }
    else{
        cout<<"Path does not exists"<<endl;
    }
return 0;
}
