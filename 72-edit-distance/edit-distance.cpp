class Solution {
public:
    int minDistance(string word1, string word2) { 
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        return f(word1, word2); }

    int f(const string& text1, const string& text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(text2.size() + 1, 0), curr(text2.size() + 1, 0);
        for (int i = 0; i <= n2; i++) {
            prev[i] = i;
        }
        for (int i = 1; i <= n1; i++) {
            curr[0]=i;
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1+min(prev[j], min(curr[j - 1], prev[j-1]));
                }
            }
            prev = curr;
        }

        return curr[n2];
    }
};