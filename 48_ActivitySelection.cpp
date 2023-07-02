#include<bits/stdc++.h>

struct activity {
    int start;
    int finish;
};

bool comparator(struct activity a, struct activity b) {
    if(a.finish<b.finish)   
        return true;

    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    struct activity activities[n];

    for(int i=0; i<n; i++) {
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }    

    sort(activities, activities+n, comparator);

    int cnt = 1;
    int lastFinish = activities[0].finish;
    for(int i=1; i<n; i++) {
        if(activities[i].start>=lastFinish) {
            cnt++;
            lastFinish = activities[i].finish;
        }
    }
    return cnt;
}
