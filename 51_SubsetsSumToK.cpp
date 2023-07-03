#include <bits/stdc++.h>

void func(int idx, vector<int> &arr, int k, vector<int> &ds, vector<vector<int>> &ans) {
    if(idx==arr.size())
    {
        if(k==0)
            ans.push_back(ds);
        
        return;
    }

    // Pick the element
    ds.push_back(arr[idx]);
    func(idx+1, arr, k-arr[idx], ds, ans);
    ds.pop_back();

    // Don't pick the element
    func(idx+1, arr, k, ds, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    func(0, arr, k, ds, ans);
    return ans;
}
