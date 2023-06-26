#include <bits/stdc++.h>

/*
// Brute Force Approach | TC-O(n^3) SC-O(1)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int longest = 1;

    for(int i=0; i<n; i++) {
        int cnt = 1;
        int x = arr[i]+1;
        while(find(arr.begin(), arr.end(), x) != arr.end()) {
            cnt++;
            x++;
        }
        longest = max(longest, cnt);
    }
    return longest;
}
*/

/*
// Better Approach | TC-O(nlogn + n) SC-O(1)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());

    int longest = 1;
    int prev = INT_MIN;
    int cnt = 0;

    for(int i=0; i<n; i++) {
        if(arr[i]==prev+1) {
            cnt++;
            prev = arr[i];
        }
        else if(arr[i]!=prev) {
            cnt = 1;
            prev = arr[i];
        }
        longest = max(longest, cnt);
    }

    return longest;
}
*/

// Alternative Better Approach | In Average case: TC-O(n) SC-O(n), In Worst case: TC-O(n^2) SC-O(n)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int longest = 1;
    unordered_set<int> hashSet(arr.begin(), arr.end());

    for(auto i: hashSet) {
        if(hashSet.find(i-1) == hashSet.end()) {
            int cnt = 1;
            int elem = i;

            while(hashSet.find(elem+1) != hashSet.end()) {
                cnt++;
                elem++;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
}
