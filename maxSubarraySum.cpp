#include <bits/stdc++.h> 

// Using Kadane's algorithm
long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = LONG_MIN;
    long long sum = 0;

    for(int i=0; i<n; i++) {
        sum += arr[i];
        maxSum = max(maxSum, sum);

        if(sum<0) {
            sum = 0;
        }
    }
    
    if(maxSum<0) 
        maxSum = 0;

    return maxSum;
}
