#include<bits/stdc++.h>
/*
// Brute Force Approach
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int i=0, j=0, curElem;

    while(i<m && j<n && k>0)
    {
        if(row1[i]<=row2[j]) {
            curElem = row1[i];
            i++;
        }
        else {
            curElem = row2[j];
            j++;
        }

        k--;
    }

    while(i<m && k>0) {
        curElem = row1[i];
            i++;
        
        k--;
    }
    
    while(j<n && k>0) {
        curElem = row2[j];
            j++;
        
        k--;
    }

    return curElem;
}
*/

// Optimized Approach
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m>n)
        return ninjaAndLadoos(row2, row1, n, m, k);

    int low = max(0, k-n), high = min(m, k);

    while(low <= high) {
        int cut1 = (low+high)>>1;
        int cut2 = k-cut1;

        int left1 = cut1==0?INT_MIN:row1[cut1-1];
        int left2 = cut2==0?INT_MIN:row2[cut2-1];
        int right1 = cut1==m?INT_MAX:row1[cut1];
        int right2 = cut2==n?INT_MAX:row2[cut2];

        if(left1<=right2 && left2<=right1)
            return max(left1, left2);
        
        else if(left1>right2)
            high = cut1-1;
        
        else
            low = cut1+1;
    }

    return -1;
}
