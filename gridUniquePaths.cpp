#include <bits/stdc++.h> 

/*
// Using memoization
int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
	if(i==m-1 && j==n-1)
		return 1;
	
	if(i>=m || j>=n)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int res = 0;

	// Go right
	res += countPaths(i, j+1, m, n, dp);

	// Go down
	res += countPaths(i+1, j, m, n, dp);

	return dp[i][j] = res;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return countPaths(0, 0, m, n, dp);
}
*/

// Using combination formula
int nCr(int n, int r) {
	double res = 1;
	for(int i=0; i<r; i++) {
		res = res*(n-i)/(i+1);
	}
	return (int)res;
}

int uniquePaths(int m, int n) {
	int N = m+n-2;
	int r = m-1;

	return nCr(N, r);
}
