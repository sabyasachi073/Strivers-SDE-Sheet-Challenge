void helper(int idx, int sum, vector<int> &num, int n, vector<int> &ans) {
	if(idx==n) {
		ans.push_back(sum);
		return;
	}

	// Consider the element
	helper(idx+1, sum+num[idx], num, n, ans);

	// Don't consider the element
	helper(idx+1, sum, num, n, ans);
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	int n = num.size();	
	helper(0, 0, num, n, ans);
	sort(ans.begin(), ans.end());
	return ans;
}
