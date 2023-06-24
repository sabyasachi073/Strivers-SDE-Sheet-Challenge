#include <bits/stdc++.h>
/*
// Better Algorithm
int findMajorityElement(int arr[], int n) {
	int reqFreq = n/2;
	map<int, int> freq;

	for(int i=0; i<n; i++) {
		freq[arr[i]]++;
	}

	for(auto i: freq)
	{
		if(i.second>reqFreq)
			return i.first;
	}

	return -1;
}
*/

// Optimized Algorithm(Moore’s Voting Algorithm)
int findMajorityElement(int arr[], int n) {
	int cnt = 0, elem;

	for(int i=0; i<n; i++) {
		if(cnt==0) {
			cnt=1;
			elem = arr[i];
		}
		else if(arr[i]==elem)
			cnt++;
		else
			cnt--;
	}

	int cnt1 = 0;
	for(int i=0; i<n; i++) {
		if(elem==arr[i]) {
			cnt1++;
		}
	}

	if(cnt1>(n/2)){
		return elem;
	}

	return -1;
}
