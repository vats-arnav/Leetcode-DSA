class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int arr[26] = {0};
            for (int j = i; j < n; j++) {
                arr[s[j] - 'a']++;
                int maxi = 0;
                int mini = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (arr[k] > 0) {
                        maxi = max(maxi, arr[k]);
                        mini = min(mini, arr[k]);
                    }
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};