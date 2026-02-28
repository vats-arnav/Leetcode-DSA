class Solution {
public:
    bool isMatch(string s, string p) { return f(s, p); }

    bool f(const string& s, const string& p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m + 1, false),curr(m + 1, false);
        prev[0]= true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};






// class Solution {
// public:
//     bool isMatch(string s, string p) { return f(s, p); }

//     bool f(const string& s, const string& p) {
//         int n = s.size();
//         int m = p.size();
//         vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//         dp[0][0] = true;

//         for (int j = 1; j <= m; j++) {
//             if (p[j - 1] == '*')
//                 dp[0][j] = dp[0][j - 1];
//         }
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 } else if (p[j - 1] == '*') {
//                     dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//                 } else {
//                     dp[i][j] = false;
//                 }
//             }
//         }

//         return dp[n][m];
//     }
// };