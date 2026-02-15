// SO
class Solution {
public:
    int f(int m, int n, vector<int>& dp) {
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                int d = 0, r = 0;
                if (i == 0 && j == 0) {
                    temp[0] = 1;
                } else {
                    if (j > 0)
                        d = temp[j-1];
                    if (i > 0)
                        r = dp[j];
                    temp[j] = r + d;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }

    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        return f(m, n, dp);
    }
};

// #tabulation
// #memoization
//  class Solution {
//  public:
//      int f(int m, int n, int i, int j, vector<vector<int>>& dp) {
//          int d = 0, r = 0;
//          if (dp[i][j] != -1) {
//              return dp[i][j];
//          }
//          if (i == m - 1 && j == n - 1) {
//              return dp[i][j] = 1;
//          }
//          if (i == m - 1) {
//              r = f(m, n, i, j + 1, dp);
//          } else if (j == n - 1) {
//              d = f(m, n, i + 1, j, dp);
//          } else {
//              d = f(m, n, i + 1, j, dp);
//              r = f(m, n, i, j + 1, dp);
//          }
//          return dp[i][j] = (d + r);
//      }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return f(m, n, 0, 0, dp);
//     }
// };