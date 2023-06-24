#include <bits/stdc++.h>

/*
// Brute Force approach
int modularExponentiation(int x, int n, int m) {
	long long res = 1;

	while(n>0) {
		res = (res*x)%m;
		n--;
	}

	return (int)res;
}
*/

// long long helper(int x, int n, int m, long long ans) {
// 	if(n==1)
// 		return ans;
	
// 	ans = (ans*ans)%m;
// 	helper(x, n/2, m, ans);

// 	if(n%2)
// 		ans *= (ans*x)%m;
// }

int modularExponentiation(int x, int n, int m) {
	long tempn;
	tempn = (n<0)? ((-1)*n) : n;

	long long res = 1;

	while(tempn>0) {
		if(tempn%2) {
			res =  res*x;
			res = res%(long)m;
			tempn--;
		}
		else{
			x = ((long)(x)*x)%(long)m;
			tempn /= 2;
		}
	}
	return (int)res;
}
