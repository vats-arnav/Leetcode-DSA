class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, -1);
        int res = 0;
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'a'] = right;
            if (freq[0] != -1 && freq[1] != -1 && freq[2] != -1) {
                res += min({freq[0], freq[1], freq[2]}) + 1;
            }
        }
        return res;
    }
};