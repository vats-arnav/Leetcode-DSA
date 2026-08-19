class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector<int> arr(256, -1);
        int ans = 0;
        while (r < n) {
            if (arr[s[r]] != -1) {
                l = max(arr[s[r]] + 1,l);
            }
            int len = r - l + 1;
            ans = max(ans, len);
            arr[s[r]] = r;
            r++;
        }
        return ans;
    }
};