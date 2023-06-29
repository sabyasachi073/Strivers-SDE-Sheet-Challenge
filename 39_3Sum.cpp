#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());
    for(int i=0; i<n-2; i++) {
        if(i!=0 && nums[i]==nums[i-1]) 
            continue;
            
        int left = i+1;
        int right = n-1;
        while(left<right) {
            int sum = nums[i]+nums[left]+nums[right];
            if(sum>K)
                right--;
            else if(sum<K)
                left++;
            else {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while(left<right && nums[left] == nums[left-1]) left++;
                while(left<right && nums[right] == nums[right+1]) right--;
            }
        }
    }
    return ans;
}
