#include <bits/stdc++.h>

void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans) {
    vis[node] = true;
    ans.push_back(node);

    for(auto i: adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, vis, ans);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> vis(V, false);
    vector<vector<int>> res;

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            vector<int> temp;
            dfs(i, adj, vis, temp);
            res.push_back(temp);
        }
    }

    return res;
}
