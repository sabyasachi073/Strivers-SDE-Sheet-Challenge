#include <bits/stdc++.h>

void func(int idx, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int target) {
	if(target==0)
	{
		ans.push_back(ds);
		return;
	}

	for(int i=idx; i<arr.size(); i++) {
		if(i!=idx && arr[i]==arr[i-1])
			continue;
		
		if(arr[i]>target) 
			break;

		ds.push_back(arr[i]);
		func(i+1, ds, ans, arr, target-arr[i]);
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	vector<vector<int>> ans;
	vector<int> ds;
	
	sort(arr.begin(), arr.end());

	func(0, ds, ans, arr, target);
	return ans;
}
