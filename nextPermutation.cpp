#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int idx = -1;

    // Finding the break point
    for(int i=n-2; i>=0; i--) {
        if(permutation[i]<permutation[i+1])
        {
            idx = i;
            break;
        }
    }

    if(idx==-1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    // FInding the smallest number greater than permutation[idx] element and swap the numbers
    for(int i=n-1; i>idx; i--) {
        if(permutation[idx]<permutation[i]) {
            swap(permutation[idx], permutation[i]);
            break;
        }
    }

    // Reverse the array from the idx index to the end of the array
    reverse(permutation.begin()+idx+1, permutation.end());

    return permutation;
}
