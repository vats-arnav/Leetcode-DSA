class Solution {
public:
    int f(int n , int m ,int i , int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
        int d = INT_MAX,r=INT_MAX;
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j] !=-1) return dp[i][j];
        if(i<n-1){
            r = f(n,m,i+1,j,grid,dp);
        }
        if(j<m-1){
            d = f(n,m,i,j+1,grid,dp);
        }
        return dp[i][j] = grid[i][j] + min(r,d);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n,m,0,0,grid,dp);
    }
};

//Recursion
// class Solution {
// public:
//     int f(int n , int m ,int i , int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
//         int d = INT_MAX,r=INT_MAX;
//         if(i==n-1 && j==m-1){
//             return grid[i][j];
//         }
//         if(i<n-1){
//             r = f(n,m,i+1,j,grid,dp);
//         }
//         if(j<m-1){
//             d = f(n,m,i,j+1,grid,dp);
//         }
//         return grid[i][j] + min(r,d);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,0));
//         return f(n,m,0,0,grid,dp);
//     }
// };