#include <bits/stdc++.h>

/*
// Brute Force
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int cnt=0;

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int xr = 0;
            for(int k=i; k<=j; k++) {
                xr = xr^arr[k];
            }
            if(xr==x)
                cnt++;
        }
    }
    return cnt;
}
*/

/*
// Better Approach
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int cnt=0;

    for(int i=0; i<n; i++) {
        int xr = 0;
        for(int j=i; j<n; j++) {
            xr = xr^arr[j];
            if(xr==x)
                cnt++;
        }
    }
    return cnt;
}
*/

// Optimized Approach
int subarraysXor(vector<int> &arr, int target)
{
    int n = arr.size();
    int cnt=0;
    map<int, int> mp;
    int xr = 0;
    mp[xr] = 1;

    for(int i=0; i<n; i++) {
        xr = xr ^ arr[i];
        
        int x = xr^target;

        cnt += mp[x];

        mp[xr]++;
    }

    return cnt;
}
