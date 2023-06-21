#include <bits/stdc++.h>

/*
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	sort(arr.begin(), arr.end());

	int repeatingNum;

	int actualSum = arr[0];
	for(int i = 1; i<n; i++) {
		if(arr[i-1]==arr[i]) 
			repeatingNum = arr[i];

		actualSum += arr[i];
	}

	int sum = (n*(n+1))/2;

	int missingNum = repeatingNum + (sum-actualSum);

	return {missingNum, repeatingNum};
}
*/

/*
// using Hasing
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int> h(n+1, 0);

	int missingNum, repeatingNum;

	for(int i = 0; i<n; i++) {
		h[arr[i]]++;
	}
	
	for(int i = 1; i<=n; i++) {
		if(h[i]==0)
			missingNum = i;
		else if(h[i]==2)
			repeatingNum = i;
	}

	return {missingNum, repeatingNum};
}
*/

// Using Math equations
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
	
	long long SN = (n*(n+1))/2;
	long long S2N = (n*(n+1)*(2*n+1))/6;
	long long S = 0, S2 = 0;

	for(int i = 0; i<n; i++) {
		S += arr[i];
		S2 += (long long)arr[i] * (long long)arr[i];
	}

	

	long long x = S - SN; // rep - mis
	long long y = S2 - S2N; // rep^2 - mis^2
	
	y = y/x; // rep + mis

	long long repeatingNum = (x+y)/2;
	long long missingNum = repeatingNum-x;

	return {(int)missingNum, (int)repeatingNum};
}
