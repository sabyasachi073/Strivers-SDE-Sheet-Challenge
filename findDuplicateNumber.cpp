#include <bits/stdc++.h>

/*
// Brute force
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	sort(arr.begin(), arr.end());

	for(int i=1; i<n; i++) {
		if(arr[i-1] == arr[i])
			return arr[i];
	}

	return -1;
}
*/

/*
// Using Frequency array
int findDuplicate(vector<int> &arr, int n) {
	 vector<int> freq(n, 0);
	for(int i=0; i<n; i++) {
		freq[arr[i]]++;
		if(freq[arr[i]]==2)
			return arr[i];
	}	 
	return -1;
}
*/

// Using Linked List Cycle method
int findDuplicate(vector<int> &arr, int n) {
	int fast = arr[0];
	int slow = arr[0];

	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while(slow!=fast);

	slow = arr[0];

	while(slow!=fast) {
		slow = arr[slow];
		fast = arr[fast];
	}

	return fast;
}
