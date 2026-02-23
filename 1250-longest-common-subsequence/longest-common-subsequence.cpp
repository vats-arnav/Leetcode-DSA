class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return f(text1, text2, text1.size() - 1, text2.size() - 1,dp);
    }

    int f(const string& text1, const string& text2, int n1, int n2,vector<vector<int>>& dp) {
        if (n1 < 0 || n2 < 0) {
            return 0;
        }
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        int match = 0;
        int nmatch = 0;
        if (text1[n1] == text2[n2]) {
            match = 1 + f(text1, text2, n1 - 1, n2 - 1,dp);
        } else {
            nmatch =
                max(f(text1, text2, n1 - 1, n2,dp), f(text1, text2, n1, n2 - 1,dp));
        }

        return dp[n1][n2] = max(match, nmatch);
    }
};