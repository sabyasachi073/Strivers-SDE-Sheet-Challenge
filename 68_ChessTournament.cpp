#include <bits/stdc++.h> 

/*
// Brute Force
int countPlayers(vector<int> &positions , int n ,  int minDistance) {
	// Counts no of players can be alloted a room with given minimum distance
	int players = 1;
	int lastPlayerPos = positions[0];
	for(int i=1; i<n; i++) {
		if(positions[i]-lastPlayerPos >= minDistance) {
			players++;
			lastPlayerPos = positions[i];
		}
	}

	return players;
}

int chessTournament(vector<int> &positions , int n ,  int c){
	sort(positions.begin(), positions.end());

	int low = 1;
	int high = positions[n-1]-positions[0];
	int distance;
	
	for(distance=low; distance<=high; distance++) {
		int noOfChessPlayers = countPlayers(positions, n, distance);
		if(noOfChessPlayers<c)
			break;
	}
	return distance-1;
}
*/

// Optimized Approach
int countPlayers(vector<int> &positions , int n ,  int minDistance) {
	// Counts no of players can be alloted a room with given minimum distance
	int players = 1;
	int lastPlayerPos = positions[0];
	for(int i=1; i<n; i++) {
		if(positions[i]-lastPlayerPos >= minDistance) {
			players++;
			lastPlayerPos = positions[i];
		}
	}

	return players;
}

int chessTournament(vector<int> &positions , int n ,  int c){
	sort(positions.begin(), positions.end());

	int low = 1;
	int high = positions[n-1]-positions[0];
	int distance;

	while(low<=high) {
		int mid = (low+high)/2;
		int noOfChessPlayers = countPlayers(positions, n, mid);

		// All chess players allocation is possible here
		if(noOfChessPlayers>=c) {
			low=mid+1;
		}
		// All chess players allocation is not possible here
		else
			high=mid-1;
	}
	return high;
}
