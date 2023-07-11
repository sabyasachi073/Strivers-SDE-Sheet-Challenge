#include <bits/stdc++.h> 

long long countDays(vector<int> time, int m, long long maxTime) {
	long long day = 1;
	long long totalTime = 0;

	for(int i=0; i<m; i++) {
		if(totalTime+time[i] <= maxTime) {
			totalTime += time[i];
		}
		else {
			day++;
			totalTime = time[i];
		}
	}
	return day;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// We have m chapters and n days
    long long sum = 0;

    int maxTime = INT_MIN;

    // We will iterate through all the chapters and calculate the sum.
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

	long long low = maxTime, high = sum;
	
	// Running binary search on the max time that can be allocated to Ayush
	while(low<=high) {
		long long mid = (low+high)/2;
		long long daysToComplete = countDays(time, m, mid);

		if(daysToComplete > n) 
			low = mid+1;
		else
			high = mid-1;
	}
	return low;
}
