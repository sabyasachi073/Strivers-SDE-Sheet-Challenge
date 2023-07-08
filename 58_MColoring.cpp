#include<bits/stdc++.h>

bool isSafe(int node, int col, vector<int> &nodeColor, vector<vector<int>> &mat) {
    for(int k=0; k<mat.size(); k++) {
        if(k!=node && mat[node][k]==1 && nodeColor[k]==col)
            return false;
    }
    return true;
}

bool solve(int node, vector<int> &color, vector<vector<int>> &mat, int m, int n) {
    if(node==n) {
        return true;
    }

    // Try each node with m colors
    for(int col=1; col<=m; col++) {
        if(isSafe(node, col, color, mat)) {
            color[node] = col;
            if(solve(node+1, color, mat, m, n))
                return true;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int> nodeColor(n, 0);
    if(solve(0, nodeColor, mat, m, n))
        return "YES";
    return "NO";
}
