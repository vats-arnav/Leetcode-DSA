class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int n = s.size();
        int m = t.size();
        int minval = INT_MAX;
        int start = -1;
        int count = 0;
        vector<int> hash(256, 0);
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < s.size()) {
            if (hash[s[r]] > 0)
                count++;
            hash[s[r]]--;

            while (count == m) {
                if (r - l + 1 < minval) {
                    start = l;
                    minval = r - l + 1;
                }
                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }
        return start == -1 ? "" : s.substr(start, minval);
    }
};