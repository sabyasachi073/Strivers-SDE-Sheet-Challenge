#include<bits/stdc++.h>

/*
// Better Approach
int longestSubarrayWithSumK(vector<int> nums, long long k) {
    int n = nums.size();
    int maxLen = 0;
    int sum = 0;

    map<int, int> mp;

    for(int i=0; i<n; i++) {
        sum += nums[i];
        if(sum==k)
            maxLen = i+1;

        else if(mp.find(sum-k) != mp.end()) {
            maxLen = max(maxLen, i-mp[sum-k]);
        }

        if(mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return maxLen;
}
*/

// Optimal Approach(Two Pointer Approach)
int longestSubarrayWithSumK(vector<int> nums, long long k) {
    int n = nums.size();
    int maxLen = 0;
    int left = 0, right = 0;
    long long sum = 0;

    while(right<n) {
        sum += nums[right];

        while(sum>k && left<=right) {
            sum -= nums[left];
            left++;
        }

        if(sum==k) {
            maxLen = max(maxLen, right-left+1);
        }

        right++;
    }

    return maxLen;
}
