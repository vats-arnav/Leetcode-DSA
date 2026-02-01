// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         return s==t;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(n!=t.length())
            return false;
        int arr[26] ={0};
        for (int i =0;i<n;i++) {
            arr[s[i] - 'a']++;
            arr[t[i] -'a']--;
        }
        for (int j=0;j<26;j++) {
            if(arr[j]!=0)
                return false;
        }

        return true;
    }
};