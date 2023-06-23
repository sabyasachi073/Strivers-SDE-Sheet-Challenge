#include <bits/stdc++.h> 

/*
// Brute force
long long getInversions(long long *arr, int n){
    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i]>arr[j])
                cnt++;
        }
    }
    return cnt;
}
*/

// Optimized solution
long long merge(long long *arr, int start, int mid, int end) {
    vector<long long> temp1, temp2;
    long long cnt = 0;

    for(int i=start; i<=mid; i++) {
        temp1.push_back(arr[i]);
    }
    
    for(int i=mid+1; i<=end; i++) {
        temp2.push_back(arr[i]);
    }

    int i=0, j=0, k=start, m=temp1.size(), n=temp2.size();

    while(i<m && j<n) {
        if(temp1[i]>temp2[j]) {
            arr[k] = temp2[j];
            k++;
            j++;
            cnt += m-i;
        }
        else {
            arr[k] = temp1[i];
            k++;
            i++;
        }
    }
    
    while(i<m) {
        arr[k] = temp1[i];
        k++;
        i++;
    }
    
    while(j<n) {
        arr[k] = temp2[j];
        k++;
        j++;
    }

    return cnt;
}

long long mergeSort(long long *arr, int start, int end) {
    if(end-start<=0) {
        return 0;
    }

    long long cnt = 0;

    int mid = (start+end)/2; 
    cnt+= mergeSort(arr, start, mid);
    cnt+= mergeSort(arr, mid+1, end);

    cnt+= merge(arr, start, mid, end);

    return cnt;
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}
