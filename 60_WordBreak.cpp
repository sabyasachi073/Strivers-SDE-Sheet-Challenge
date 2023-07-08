#include <bits/stdc++.h> 

vector<string>  wordBreakHelper(int idx, string &s, unordered_set<string> &dictSet, 
unordered_map<int, vector<string>> &dp, int n) {
    if(idx==n)
        return {""};
    
    vector<string> subPart, completePart;
    string word = "";

    for(int i=idx; i<n; i++) {
        word += s[i];
        if(dictSet.find(word)==dictSet.end())
            continue;

        subPart = wordBreakHelper(i+1, s, dictSet, dp, n);

        for(int j=0; j<subPart.size(); j++) {
            if(subPart[j].size()!=0) {
                subPart[j] = word + " " + subPart[j];
            }
            else
                subPart[j] = word;
        }

        for(auto str: subPart)
            completePart.push_back(str);
    }

    return dp[idx] = completePart;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Stores all the possible strings strating from an index until the end of the string
    unordered_map<int, vector<string>> dp;
    
    // Stores the words present in dictionary(It helps in searching the words faster)
    unordered_set<string> dictSet;

    for(auto word: dictionary) {
        dictSet.insert(word);
    }

    return wordBreakHelper(0, s, dictSet, dp, s.size());
}
