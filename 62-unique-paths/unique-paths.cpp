class Solution {
public:
    int f(int m, int n, int i, int j, vector<vector<int>>& dp) {
        int d = 0, r = 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == m - 1 && j == n - 1) {
            return dp[i][j] = 1;
        }
        if (i == m - 1) {
            r = f(m, n, i, j + 1, dp);
        } else if (j == n - 1) {
            d = f(m, n, i + 1, j, dp);
        } else {
            d = f(m, n, i + 1, j, dp);
            r = f(m, n, i, j + 1, dp);
        }
        return dp[i][j] = (d + r);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m, n, 0, 0, dp);
    }
};