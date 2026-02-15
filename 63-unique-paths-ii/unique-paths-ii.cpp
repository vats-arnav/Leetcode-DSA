class Solution {
public:
    int f(int m, int n, vector<int>& dp,vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                int d = 0, r = 0;
                if(obstacleGrid[i][j]==1){
                    temp[j]=0;
                }
                else if (i == 0 && j == 0) {
                    temp[0] = 1;
                } 
                else {
                    if (j > 0)
                        d = temp[j - 1];
                    if (i > 0)
                        r = dp[j];
                    temp[j] = r + d;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        return f(m, n, dp,obstacleGrid);
    }
};