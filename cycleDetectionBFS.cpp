#include <bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<pair<bool, int>> vis(n, {false, -1});
    vector<int> adj[n];

    for(auto edge: edges) {
        int u = edge[0]-1; 
        int v = edge[1]-1; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    for(int i=0; i<n; i++) {
        if(vis[i].first==false) {
            q.push(i);
            vis[i] = {true, -1};

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto adjNode: adj[node]) {
                    if(vis[adjNode].first==false){
                        vis[adjNode]={true, node};
                        q.push(adjNode);
                    }
                    else if(vis[node].second != adjNode)
                        return "Yes";
                }
            }
        }
    }

    return "No";
}
