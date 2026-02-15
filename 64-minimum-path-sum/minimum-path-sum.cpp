//SO
class Solution {
public:
    int f(int n, int m, vector<vector<int>>& grid, vector<int>& dp) {
        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++) {
                int d = INT_MAX, r = INT_MAX;
                if (i == 0 && j == 0)
                    temp[0] = grid[0][0];
                else {
                    if (j > 0) {
                        r = temp[j-1];
                    }
                    if (i > 0) {
                        d = dp[j];
                    }
                    temp[j] = grid[i][j] + min(r, d);
                }
            }
            dp = temp;
        }
        return dp[m - 1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m, 0);
        return f(n, m, grid, dp);
    }
};









// Tabulation
// class Solution {
// public:
//     int f(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 int d = INT_MAX, r = INT_MAX;
//                 if (i == 0 && j == 0)
//                     dp[i][j] = grid[0][0];
//                 else {
//                     if (i > 0) {
//                         r = dp[i - 1][j];
//                     }
//                     if (j > 0) {
//                         d = dp[i][j - 1];
//                     }
//                     dp[i][j] = grid[i][j] + min(r, d);
//                 }
//             }
//         }
//         return dp[n - 1][m - 1];
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return f(n, m, grid, dp);
//     }
// };

// Memoization
//  class Solution {
//  public:
//      int f(int n , int m ,int i , int j, vector<vector<int>>&
//      grid,vector<vector<int>>& dp){
//          int d = INT_MAX,r=INT_MAX;
//          if(i==n-1 && j==m-1){
//              return grid[i][j];
//          }
//          if(dp[i][j] !=-1) return dp[i][j];
//          if(i<n-1){
//              r = f(n,m,i+1,j,grid,dp);
//          }
//          if(j<m-1){
//              d = f(n,m,i,j+1,grid,dp);
//          }
//          return dp[i][j] = grid[i][j] + min(r,d);
//      }
//      int minPathSum(vector<vector<int>>& grid) {
//          int n = grid.size();
//          int m = grid[0].size();
//          vector<vector<int>> dp(n,vector<int>(m,-1));
//          return f(n,m,0,0,grid,dp);
//      }
//  };

// Recursion
//  class Solution {
//  public:
//      int f(int n , int m ,int i , int j, vector<vector<int>>&
//      grid,vector<vector<int>>& dp){
//          int d = INT_MAX,r=INT_MAX;
//          if(i==n-1 && j==m-1){
//              return grid[i][j];
//          }
//          if(i<n-1){
//              r = f(n,m,i+1,j,grid,dp);
//          }
//          if(j<m-1){
//              d = f(n,m,i,j+1,grid,dp);
//          }
//          return grid[i][j] + min(r,d);
//      }
//      int minPathSum(vector<vector<int>>& grid) {
//          int n = grid.size();
//          int m = grid[0].size();
//          vector<vector<int>> dp(n,vector<int>(m,0));
//          return f(n,m,0,0,grid,dp);
//      }
//  };