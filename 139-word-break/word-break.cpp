class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dp[j] && wordSet.count(word)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
/*
Recursion
class Solution {
public:
    bool backtrack(int start, const string& s,
                   const unordered_set<string>& wordSet,
                   unordered_map<int, bool>& memo) {
        if (start == s.length()) {
            return true;
        }

        if (memo.find(start) != memo.end()) {
            return memo[start];
        }

        for (int end = start + 1; end <= s.length(); ++end) {
            string prefix = s.substr(start, end - start);

            if (wordSet.count(prefix) && backtrack(end, s, wordSet, memo)) {
                return memo[start] = true;
            }
        }

        return memo[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return backtrack(0, s, wordSet, memo);
    }
};
*/