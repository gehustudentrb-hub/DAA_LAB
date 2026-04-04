#include <bits/stdc++.h>
using namespace std;

void dijkstra(int V, vector<pair<int,int>> adj[], int src)
{
    vector<int> dist(V, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;

            if(d + wt < dist[adjNode])
            {
                dist[adjNode] = d + wt;

                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "\nShortest distances:\n";

    for(int i = 0; i < V; i++)
    {
        cout << "Node " << i
             << " = " << dist[i] << endl;
    }
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
    }

    int src;

    cout << "\nEnter source node: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}