#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<bool> vis(vertex, false);
    vector<int> adj[vertex];

    for(auto edge: edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<int> res;

    queue<int> q;
    for(int i=0; i<vertex; i++) {
        if(!vis[i]) {
            q.push(i);
            vis[i] = true;

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                res.push_back(node);
                
                sort(adj[node].begin(), adj[node].end());

                for(auto adjNode: adj[node]) {
                    if(!vis[adjNode]){
                        vis[adjNode]=true;
                        q.push(adjNode);
                    }
                }
            }
        }
    }

    return res;
}
