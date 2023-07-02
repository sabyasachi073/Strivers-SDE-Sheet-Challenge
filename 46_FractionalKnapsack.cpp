#include <bits/stdc++.h> 

bool comparator(pair<int, int> a, pair<int, int> b) {
    double x = a.second/(double)a.first;
    double y = b.second/(double)b.first;

    if(x>y) return true;
    return false;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comparator);
    
    double profit = 0.0;

    int i = 0;

    while(w>0 && i<n) {
        int weight = items[i].first;
        int value = items[i].second;
        if(weight<=w) {
            w -= weight;
            profit += value;
        }
        else {
            profit += (value/(double)weight)*w;
            w=0;
        }
        i++;
    }
    return profit;
}
