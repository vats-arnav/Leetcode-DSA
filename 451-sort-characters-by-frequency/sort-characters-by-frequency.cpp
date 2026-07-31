class Solution {
public:
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        return p1.first > p2.first;
    }
    string frequencySort(string s) {
        pair<int, char> freq[256];

        for (int i = 0; i < 256; i++) {
            freq[i] = {0, (char)i};
        }
        for (char ch : s) {
            freq[ch].first++;
        }
        string ans = "";
        sort(freq, freq + 256, comparator);
        for (int i = 0; i < 256; i++) {
            if (freq[i].first > 0)
                ans += string(freq[i].first, freq[i].second);
        }
        return ans;
    }
};