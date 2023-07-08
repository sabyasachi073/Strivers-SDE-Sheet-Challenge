#include <bits/stdc++.h> 

/*
// Recursive approach
void func(string ds, string &s, vector<bool> &visited, vector<string> &ans) {
    if(ds.size()==s.size()) {
        ans.push_back(ds);
        return;
    }

    for(int i=0; i<s.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            func(ds+s[i], s, visited, ans);
            visited[i] = false;
        }
    }
}

vector<string> findPermutations(string &s) {
    vector<bool> visited(s.size(), false);
    vector<string> ans;
    func("", s, visited, ans);
    return ans;
}
*/

// Backtracking approach
void func(int idx, string s, vector<string> &ans) {
    if(idx==s.size()) {
        ans.push_back(s);
        return;
    }

    for(int i=idx; i<s.size(); i++) {
        swap(s[idx], s[i]);
        func(idx+1, s, ans);
        swap(s[idx], s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<bool> visited(s.size(), false);
    vector<string> ans;
    func(0, s, ans);
    return ans;
}
