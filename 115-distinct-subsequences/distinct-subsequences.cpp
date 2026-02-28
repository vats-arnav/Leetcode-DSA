class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.size() + 1, vector<double>(t.size() + 1, -1));
        return f(s, t, dp);
    }

    int f(const string& text1, const string& text2, vector<vector<double>>& dp) {
        int n1 = text1.size();
        int n2 = text2.size();
        for (int i = 1; i <= n2; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[n1][n2];
    }
};
