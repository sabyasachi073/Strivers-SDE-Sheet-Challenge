#include <bits/stdc++.h>

/*
// Brute Force
int search(int* arr, int n, int key) {
    for(int i = 0; i<n; i++) {
        if(arr[i]==key)
            return i;
    }
    return -1;
}
*/

// Optimized Approach
int search(int* arr, int n, int key) {
    int low=0, high=n-1;

    while(low<=high) {
        int mid = (low+high)/2;

        if(arr[mid]==key)
            return mid;

        else if(arr[low] <= arr[mid]) {
            if(arr[low]<=key && key<arr[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else {
            if(arr[mid]<key && key<=arr[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }

    return -1;
}
