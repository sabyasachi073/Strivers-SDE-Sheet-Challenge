#include <bits/stdc++.h>

/*
// Brute Force | TC-O(n^4) SC-O(1)
string fourSum(vector<int> arr, int target, int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                for(int l=k+1; l<n; l++) {
                    long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target)
                        return "Yes";
                }
            }        
        }
    }
    return "No";
}
*/

/*
// Better Approach | TC-O(n^3) SC-O(n)
string fourSum(vector<int> arr, int target, int n) {

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            set<int> hashSet;
            for(int k=j+1; k<n; k++) {
                long long sum = arr[i] + arr[j] + arr[k];
                int rem = target-sum;
                if(hashSet.find(rem) != hashSet.end())
                    return "Yes";

                hashSet.insert(arr[k]);
            }        
        }
    }
    return "No";
}
*/

// Optimal Approach(Two Pointer Approach) | TC-O(n^3) SC-O(1)
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++) {
        if(i>0 && arr[i]==arr[i-1])
            continue;

        for(int j=i+1; j<n; j++) {
            if(j>0 && arr[j]==arr[j-1])
                continue;
            int k = j+1;
            int l = n-1;
            while(k<l) {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];

                if(sum>target)
                    l--;
                else if(sum<target)
                    k++;
                else
                    return "Yes";        
            }
        }
    }
    return "No";
}
