int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0, j=0;
    int maxOne=0;
    int zeroes=0;

    while(j<n) {
        if(arr[j]==0) {
            zeroes++;
        }

        while(zeroes>k) {
            if(arr[i]==0)
                zeroes--;
            i++;
        }
        maxOne = max(maxOne, j-i+1);
        j++;
    }
    return maxOne;
}
