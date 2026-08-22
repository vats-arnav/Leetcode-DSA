class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        while (l < g.size() && r < s.size()) {
            if (g[l] <= s[r]) {
                l++;
            }
            r++;
        }
        return l;
    }
};