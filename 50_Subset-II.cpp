#include <bits/stdc++.h> 
void helper(int idx, vector<int> &ds, vector<int> &arr, int n, vector<vector<int>> &ans) {
    ans.push_back(ds);

    for(int i=idx; i<n; i++) {
        if(i!=idx && arr[i] == arr[i-1]) 
            continue;

        ds.push_back(arr[i]);
        helper(i+1, ds, arr, n, ans);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    helper(0, ds, arr, n, ans);
    return ans;
}
