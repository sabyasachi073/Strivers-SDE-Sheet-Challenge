#include <bits/stdc++.h>

vector<long long int> generateRow(int r) {
  vector<long long int> row;
  long long int res = 1;
  // Pushing the 1st element of the row
  row.push_back(res);
  
  // Pushing remaining elements of the row
  for(int c=1; c<r; c++) {
    res = res * (r-c);
    res = res / c;
    row.push_back(res);
  }

  return row;
}

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  for(int i=1; i<=n; i++) {
    ans.push_back(generateRow(i));
  }

  return ans;
}
