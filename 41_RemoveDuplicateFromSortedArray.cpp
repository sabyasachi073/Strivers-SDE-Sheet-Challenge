#include <bits/stdc++.h>
/*
// Brute Force
int removeDuplicates(vector<int> &arr, int n) {
	set<int> st;

	int i;
	for(i=0; i<n; i++) {
		st.insert(arr[i]);
	}

	i=0;
	for(auto ele: st) {
		arr[i++] = ele;
	}

	return i;
}
*/

// Optimal Approach(Two Pointer approach)
int removeDuplicates(vector<int> &arr, int n) {
	int i = 0;
	for(int j=1; j<n; j++) {
		if(arr[i]!=arr[j]) {
			i++;
			arr[i] = arr[j];
		}
	}
	return i+1;
}
