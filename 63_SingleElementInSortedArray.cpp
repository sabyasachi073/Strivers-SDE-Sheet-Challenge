#include<bits/stdc++.h>
/*
// Brute Force
int singleNonDuplicate(vector<int>& arr)
{
	unordered_map<int, int> freq;

	for(auto i: arr) {
		freq[i]++;
	}

	for(auto num: freq) {
		if(num.second==1)
			return num.first;
	}
	return -1;
}
*/

/*
// Better Approach
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	if(arr[0]!=arr[1])
		return arr[0];
	
	if(arr[n-2]!=arr[n-1])
		return arr[n-1];

	for(int i=1; i<n-2; i++) {
		if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])
			return arr[i];
	}

	return -1;
}
*/

// Optimized Approach
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	if(arr[0]!=arr[1])
		return arr[0];
	
	if(arr[n-2]!=arr[n-1])
		return arr[n-1];

	int low = 1, high = n-2;

	while(low<=high) {
		int mid = (low+high)/2;

		if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
			return arr[mid];
		
		if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1]))
			low = mid+1;

		else
			high = mid-1;
	}

	return -1;
}
