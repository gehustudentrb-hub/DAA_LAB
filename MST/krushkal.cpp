#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, wt;
};

bool cmp(Edge a, Edge b)
{
    return a.wt < b.wt;
}

class DSU
{
    vector<int> parent;

public:

    DSU(int V)
    {
        parent.resize(V);

        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }

        return parent[node] =
               findParent(parent[node]);
    }

    void unionSet(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        parent[pu] = pv;
    }
};

void kruskal(int V, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(V);

    int sum = 0;

    cout << "\nEdges in MST:\n";

    for(auto it : edges)
    {
        int u = it.u;
        int v = it.v;
        int wt = it.wt;
        if(dsu.findParent(u) !=
           dsu.findParent(v))
        {
            dsu.unionSet(u, v);

            sum += wt;

            cout << u
                 << " - "
                 << v
                 << " = "
                 << wt << endl;
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

    vector<Edge> edges;

    cout << "\nEnter edges (u v wt):\n";

    for(int i = 0; i < E; i++)
    {
        Edge temp;

        cin >> temp.u
            >> temp.v
            >> temp.wt;

        edges.push_back(temp);
    }

    kruskal(V, edges);

    return 0;
}