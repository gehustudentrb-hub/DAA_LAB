#include <bits/stdc++.h>
using namespace std;

void prims(int V, vector<pair<int,int>> adj[])
{
    vector<int> visited(V, 0);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    int sum = 0;
    pq.push({0, 0});

    while(!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        if(visited[node] == 1)
        {
            continue;
        }
        visited[node] = 1;
        sum += wt;
        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;

             if(visited[adjNode] == 0)
             {
                 pq.push({edgeWt, adjNode});
             }
            if(!visited[adjNode])
            {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    cout << "\nMinimum Spanning Tree Weight = "
         << sum;
}

int main()
{
    int V, E;

    cout << "Enter vertices: ";
    cin >> V;

    cout << "Enter edges: ";
    cin >> E;

    vector<pair<int,int>> adj[V];

    cout << "\nEnter edges (u v wt):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v, wt;

        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    prims(V, adj);

    return 0;
}