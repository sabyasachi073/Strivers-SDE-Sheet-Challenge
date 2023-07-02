#include <bits/stdc++.h> 

bool comparator(vector<int> j1, vector<int> j2) {
    if(j1[1]>j2[1]) return true;
    
    return false;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);

    int maxDeadline = 0;
    for(auto job: jobs) {
        maxDeadline = max(maxDeadline, job[0]);
    }

    int profit = 0;

    vector<int> slots(maxDeadline+1, -1);

    for(auto job: jobs) {
        for(int i=job[0]; i>=1; i--) {
            if(slots[i]==-1)
            {
                profit += job[1];
                slots[i] = 1;
                break;
            }
        }
    }
    return profit;
}
