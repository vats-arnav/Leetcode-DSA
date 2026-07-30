class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[26] = {0};
        int arr2[26] = {0};

        for (char c : s) {
            arr1[c - 'a']++;
        }
        for (char c : t) {
            arr2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
};