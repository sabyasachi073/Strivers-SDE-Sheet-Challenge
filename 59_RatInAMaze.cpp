#include <bits/stdc++.h> 
void func(int i, int j, vector<vector<int>> &resMaze, vector<vector<int>> &ans, int di[4], 
          int dj[4], vector<vector<int>> &maze, int n) {
  if(i==n-1 && j==n-1) {
    resMaze[i][j]=1;
    vector<int> temp;
    for(auto a: resMaze) {
      temp.insert(temp.end(), a.begin(), a.end());
    }
    resMaze[i][j]=0;
    ans.push_back(temp);
    return;
  }

  for(int k=0; k<4; k++) {
    int nexti = i+di[k];
    int nextj = j+dj[k];
    if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && maze[nexti][nextj]==1 && resMaze[nexti][nextj]==0) {
      resMaze[i][j] = 1;
      func(nexti, nextj, resMaze, ans, di, dj, maze, n);
      resMaze[i][j] = 0;
    }
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> ans;
  vector<vector<int>> resMaze(n, vector<int>(n, 0));
  
  int di[] = {0, 0, -1, 1};
  int dj[] = {-1, 1, 0, 0};

  if(maze[0][0]==1) {
    func(0, 0, resMaze, ans, di, dj, maze, n);
  }

  return ans;

}
