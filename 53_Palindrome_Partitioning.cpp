#include <bits/stdc++.h> 

bool isPalindrome(string s, int left, int right) {
    while(left<=right) {
        if(s[left++]!=s[right--])
            return false;
    }
    return true;
}

void func(int idx, vector<string> &ds, string s, vector<vector<string>> &ans) {
    if(idx==s.size()){
        ans.push_back(ds);
        return;
    }
    
    for(int i=idx; i<s.size(); i++) {
        if(isPalindrome(s, idx, i)) {
            ds.push_back(s.substr(idx, i-idx+1));
            func(i+1, ds, s, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> ds;
    func(0, ds, s, ans);
    return ans;
}
