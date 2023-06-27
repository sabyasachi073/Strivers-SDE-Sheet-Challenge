#include <bits/stdc++.h> 

/*
// Brute Force
int uniqueSubstrings(string input)
{
    int n = input.size();
    if(n==0)
        return 0;

    int length = 1;

    for(int i=0, j; i<n; i++) {
        unordered_set<int> st;
        for(j=i; j<n; j++) {
            if(st.find(input[j])!=st.end()) {
                break;
            }
            st.insert(input[j]);
        }
        length = max(length, j-i);
    }
    return length;
}
*/

/*
// Better Solution
int uniqueSubstrings(string input)
{
    int n = input.size();
    int left=0, right=0;
    int length = 0;
    set<int> st;

    while(right<n) {
        while(st.find(input[right])!=st.end()) {
            st.erase(input[left]);
            left++;
        }
        length = max(length, right-left+1);
        st.insert(input[right]);
        right++;
    }

    return length;
}
*/

// Optimal Solution 1
int uniqueSubstrings(string input)
{
    int n = input.size();
    int left=0, right=0;
    int length = 0;
    vector<int> mp(256, -1);

    while(right<n) {
        if(mp[input[right]] != -1)
            left = max(left, mp[input[right]]+1);

        length = max(length, right-left+1);
        mp[input[right]] = right;
        right++;
    }

    return length;
}

/*
// Optimal Solution 2
int uniqueSubstrings(string input)
{
    int n = input.size();
    int left=0, right=0;
    int length = 0;
    map<int, int> mp;

    while(right<n) {
        if(mp.find(input[right])!=mp.end())
            left = max(left, mp[input[right]]+1);

        length = max(length, right-left+1);
        mp[input[right]] = right;
        right++;
    }

    return length;
}
*/
