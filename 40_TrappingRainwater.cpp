#include <bits/stdc++.h> 

long getTrappedWater(long *height, int n){
    long res = 0;

    long l=0, r=n-1;
    long leftMax=0, rightMax=0;
    while(l<=r) {
        if(height[l] <= height[r]) {
            if(leftMax<height[l])
                leftMax = height[l];
            else
                res += leftMax-height[l];
            
            l++;
        }
        else {
            if(rightMax<height[r])
                rightMax = height[r];
            else
                res += rightMax-height[r];
            r--;
        }
    }
    return res;
}
