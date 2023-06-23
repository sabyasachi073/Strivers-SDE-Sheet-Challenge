#include<bits/stdc++.h>

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();
    int low = 0, high = (m*n)-1;

    while(low<=high) {
        int mid = (low+high)/2;
        int i = mid/n;
        int j = mid%n;
    
        if(mat[i][j]==target)
            return true;
        
        if(mat[i][j]>target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
