#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int left=0, right=m-1, top=0, bottom=n-1;

    while(left<right && top<bottom) {
        int temp = mat[top][left];
        
        // Left to Right
        for(int i=left; i<=right; i++) {
            swap(temp, mat[top][i]);
        }
        top++;

        // Top to Bottom
        for(int i=top; i<=bottom; i++) {
            swap(temp, mat[i][right]);
        }
        right--;
        
        // Right to Left
        for(int i=right; i>=left; i--) {
            swap(temp, mat[bottom][i]);
        }
        bottom--;

        // Bottom to Top
        for(int i=bottom; i>=top; i--) {
            swap(temp, mat[i][left]);
        }
        left++;

        mat[top-1][left-1]=temp;
    }
    
}
