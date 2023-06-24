#include <bits/stdc++.h>

/*
// Brute Force
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();
   vector<vector<int>> ans;

   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         if(arr[i]+arr[j]==s) {
            if(arr[i]<arr[j])
               ans.push_back({arr[i],arr[j]});
            else
               ans.push_back({arr[j],arr[i]});
         }
      }
   }
   sort(ans.begin(), ans.end());
   return ans;
}
*/

// Optimized approach
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();
   unordered_multiset<int> hashmap;
   multiset<vector<int>> ans;

   for(int i=0; i<n; i++) {
      int more = s-arr[i];
      if(hashmap.find(more)!=hashmap.end())
      {
         int cnt = hashmap.count(more);
         
         if(arr[i]<more)
            while(cnt--)
               ans.insert({arr[i], more});
         else
            while(cnt--)
               ans.insert({more, arr[i]});
      }
      hashmap.insert(arr[i]);
   }

   return vector<vector<int>>(ans.begin(), ans.end());
}
