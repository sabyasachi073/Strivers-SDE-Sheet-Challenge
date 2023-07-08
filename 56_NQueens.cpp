#include<bits/stdc++.h>

void queen(int col, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &left, vector<int> &upperDiag, vector<int> &lowerDiag, int n) {
    if(col==n)
    {
        vector<int> result=board[0];
        for(int i=1; i<n; i++) {
            result.insert(result.end(), board[i].begin(), board[i].end());
        }

        ans.push_back(result);
        return;
    }

    for(int row=0; row<n; row++) {
        if(left[row]==0 && upperDiag[n-1+row-col]==0 && lowerDiag[row+col]==0) {
            board[row][col] = 1;

            left[row]=1;
            upperDiag[n-1+row-col]=1;
            lowerDiag[row+col]=1;
            
            queen(col+1, board, ans, left, upperDiag, lowerDiag, n);

            board[row][col] = 0;

            left[row]=0;
            upperDiag[n-1+row-col]=0;
            lowerDiag[row+col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> left(n, 0);
    vector<int> upperDiag(2*n-1, 0);
    vector<int> lowerDiag(2*n-1, 0);

    queen(0, board, ans, left, upperDiag, lowerDiag, n);
    return ans;
}
