class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, -1));
        return f(text1, text2, dp);
    }

    int f(const string& text1, const string& text2, vector<vector<int>>& dp) {
        int n1 = text1.size();
        int n2 = text2.size();
        for (int i = 0; i <= n2; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j- 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};

// memoization
//  class Solution {
//  public:
//      int longestCommonSubsequence(string text1, string text2) {
//          vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
//          return f(text1, text2, text1.size() - 1, text2.size() - 1,dp);
//      }

//     int f(const string& text1, const string& text2, int n1, int
//     n2,vector<vector<int>>& dp) {
//         if (n1 < 0 || n2 < 0) {
//             return 0;
//         }
//         if(dp[n1][n2]!=-1) return dp[n1][n2];
//         int match = 0;
//         int nmatch = 0;
//         if (text1[n1] == text2[n2]) {
//             match = 1 + f(text1, text2, n1 - 1, n2 - 1,dp);
//         } else {
//             nmatch =
//                 max(f(text1, text2, n1 - 1, n2,dp), f(text1, text2, n1, n2 -
//                 1,dp));
//         }

//         return dp[n1][n2] = max(match, nmatch);
//     }
// };