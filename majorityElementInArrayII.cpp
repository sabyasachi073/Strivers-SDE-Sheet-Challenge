#include <bits/stdc++.h>
// Reading Material: https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1 = 0, cnt2 = 0, elem1=INT_MIN, elem2=INT_MAX;
    int n = arr.size();

    for(int i=0; i<n; i++) {
        if(cnt1==0 && elem2!=arr[i]) {
            cnt1++;
            elem1 = arr[i];
        }
        else if(cnt2==0 && elem1!=arr[i]) {
            cnt2++;
            elem2 = arr[i];
        }
        else if(arr[i]==elem1)
            cnt1++;
        else if(arr[i]==elem2)
            cnt2++;
        else {
            cnt1--;
            cnt2--;
        }            
    }

    cnt1=0, cnt2=0;
    for(int i=0; i<n; i++) {
        if(arr[i]==elem1)
            cnt1++;
        else if(arr[i]==elem2)
            cnt2++;
    }

    vector<int> temp;

    int mini = (int)(n/3)+1;
    if(cnt1>=mini)
        temp.push_back(elem1);
    if(cnt2>=mini)
        temp.push_back(elem2);

        return temp;
}
