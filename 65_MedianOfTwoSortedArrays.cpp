class Solution {
public:
/*
    // Brute Force Approach
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0, j=0, m=nums1.size(), n=nums2.size();

        while(i<m && j<n) {
            if(nums1[i]<=nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }

            else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m) {
            arr.push_back(nums1[i]);
            i++;
        }

        while(j<n) {
            arr.push_back(nums2[j]);
            j++;
        }

        int len = arr.size();
        if(len%2 == 1) {
            return arr[len/2];
        }
        
        return (arr[len/2]+arr[(len/2)-1])/(double)2;
    }
*/

/*
    // Optimized Brute Force Approach
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, m=nums1.size(), n=nums2.size(), k = 0;
        int medianIndex = ((m+n)/2)+1;
        int cur = INT_MIN, prev;

        while(i<m && j<n && k!=medianIndex) {
            prev = cur;
            if(nums1[i]<=nums2[j]) {
                cur = nums1[i];
                i++;
            }

            else {
                cur = nums2[j];
                j++;
            }

            k++;   
        }

        while(i<m && k!=medianIndex) {
            prev = cur;
            cur = nums1[i];
            i++;
            k++;
        }

        while(j<n && k!=medianIndex) {
            prev = cur;
            cur = nums2[j];
            j++;
            k++;
        }

        if((m+n)%2 == 1) {
            return cur;
        }
        
        return (cur+prev)/(double)2;
    }
*/

    // Optimized Approach
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        // To ensure that binary search happens on the smaller array
        if(m>n)
            return findMedianSortedArrays(nums2, nums1);

        int low=0, high=m, medianPos=(m+n+1)/2;
        while(low<=high) {
            int cut1=(low+high)/2;
            int cut2=medianPos-cut1;

            int left1 = cut1==0?INT_MIN:nums1[cut1-1];
            int left2 = cut2==0?INT_MIN:nums2[cut2-1];
            int right1 = cut1==m?INT_MAX:nums1[cut1];
            int right2 = cut2==n?INT_MAX:nums2[cut2];

            if(left1<=right2 && left2<=right1) {
                if((m+n)%2 == 1) {
                    return max(left1, left2);
                }
                else
                    return (max(left1, left2)+min(right1, right2))/2.0;
            }

            if(left1>right2)
                high = cut1-1;
            else
                low = cut1+1;
        }
        return 0.0;
    }
};
