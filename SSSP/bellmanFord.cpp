#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, wt;
};

void bellmanFord(int V, vector<Edge>& edges, int src)
{
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 0; i < V - 1; i++)
    {
        for(auto it : edges)
        {
            int u = it.u;
            int v = it.v;
            int wt = it.wt;

            if(dist[u] != INT_MAX &&
               dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
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

    vector<Edge> edges;

    cout << "\nEnter edges (u v wt):\n";

    for(int i = 0; i < E; i++)
    {
        Edge temp;

        cin >> temp.u >> temp.v >> temp.wt;

        edges.push_back(temp);
    }

    int src;

    cout << "\nEnter source node: ";
    cin >> src;

    bellmanFord(V, edges, src);

    return 0;
}