class Solution {
public:
    int f(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        int min_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d = INT_MAX, dl = INT_MAX, dr = INT_MAX;
                min_val = 0;
                if (i == 0) {
                    dp[0][j] = matrix[0][j];
                } else {
                    if (i > 0) {
                        d = dp[i - 1][j];
                    }
                    if (i > 0 && j > 0) {
                        dl = dp[i - 1][j - 1];
                    }
                    if (i > 0 && j < m - 1) {
                        dr = dp[i - 1][j + 1];
                    }
                    dp[i][j] = matrix[i][j] + min(dr, min(d, dl));
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), INT_MAX));
        return f(matrix, dp);
    }
};