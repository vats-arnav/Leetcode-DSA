class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size() + 1,
                               vector<int>(str2.size() + 1, -1));
        // int len = str1.size() + str2.size() - f(word1, word2);
        return f(str1, str2, dp);
    }
    string f(const string& text1, const string& text2,
             vector<vector<int>>& dp) {
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
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n1;
        int j = n2;
        string ans = "";

        while (i > 0 && j > 0) {

            if (text1[i - 1] == text2[j - 1]) {
                ans += text1[i - 1];
                i--;
                j--;
            }

            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += text1[i - 1];
                i--;
            } else {
                ans += text2[j - 1];
                j--;
            }
        }
        while (i > 0) {
            ans += text1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += text2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};