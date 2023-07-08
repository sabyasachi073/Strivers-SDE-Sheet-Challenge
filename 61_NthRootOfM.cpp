#include <bits/stdc++.h>

/*
// Brute force
int NthRoot(int n, int m) {
  for(int i=1; i<m; i++) {
    long long int product = 1;
    for(int j=1; j<=n; j++) {
      product *= i;
    }
    if(product == m)
      return i;
    else if(product>m)
      break;
  }
  return -1;
}
*/

// Optimized Approach
/*
  Return 0 if product<m
  Return 1 if product==m
  Return 2 if product>m
*/
int func(int num, int n, int m) {
  long long int product = 1;
  for(int i=1; i<=n; i++) {
    product *= num;
    if(product>m)
      return 2;
  }
  if(product==m)
    return 1;
  
  return 0;
}

int NthRoot(int n, int m) {
  int left=1, right=m;
  while(left<=right) {
    int mid = (left+right)/2;
    int temp = func(mid, n, m);
    if(temp==0)
      left = mid+1;
    else if(temp==2)
      right = mid-1;
    else
      return mid;
  }
  return -1;
}
