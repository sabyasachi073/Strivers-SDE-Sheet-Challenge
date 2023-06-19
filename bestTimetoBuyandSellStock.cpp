#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i=1; i<n; i++) {
        maxProfit = max(maxProfit, (prices[i]-minPrice));
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}
