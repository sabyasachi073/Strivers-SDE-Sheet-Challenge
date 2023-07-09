#include<bits/stdc++.h>
/*
// Brute force approach
int getMedian(vector<vector<int>> &matrix)
{
    vector<int> temp;
    for(auto arr: matrix) {
        temp.insert(temp.end(), arr.begin(), arr.end());
    }

    sort(temp.begin(), temp.end());
    int n = temp.size();

    return temp[n/2];
}
*/
// Optimized approach
int countSmallerElem(vector<vector<int>> &matrix, int assumedMedian) {
    int count = 0;
    
    for(int i=0; i<matrix.size(); i++) {
      int left = 0;
      int right = matrix[i].size()-1;

      while(left<=right) {
        int mid = (left+right)/2;
        if(matrix[i][mid]<=assumedMedian)
            left = mid+1;
        else
            right = mid-1;
      }

      count += left;
    }

    return count;
}

int getMedian(vector<vector<int>> &matrix)
{
    int left=1, right=1e5;
    int totalElem =(matrix.size())*(matrix[0].size());
    int medianIndex = totalElem/2;
    // cout<<medianIndex<<" "<<totalElem<<endl;
    while(left<=right) {
        int assumedMedian = (left+right)/2;
        int noOfSmallerElem = countSmallerElem(matrix, assumedMedian);
        
        if(noOfSmallerElem<=medianIndex)
            left = assumedMedian+1;
        else
            right = assumedMedian-1;
    }
    return left;
}
