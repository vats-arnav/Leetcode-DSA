// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         vector<int> freq(3, 0);

//         int res = 0;
//         int left = 0;

//         for (int right = 0; right < s.length(); right++) {
//             freq[s[right] - 'a']++;

//             while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
//                 res += (s.length() - right);
//                 freq[s[left] - 'a']--;
//                 left++;
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, -1);
        int res = 0;
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'a'] = right;
            if (freq[0] != -1 && freq[1] != -1 && freq[2] != -1) {
                res += min(freq[0], min(freq[1], freq[2])) + 1;
            }
        }
        return res;
    }
};