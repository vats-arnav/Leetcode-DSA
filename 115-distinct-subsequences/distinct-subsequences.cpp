class Solution {
public:
    int numDistinct(string s, string t) {
        return f(s, t);
    }

    int f(const string& text1, const string& text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<double> prev(n2+1,0);
        prev[0]=1;
        for (int i = 1; i <= n1; i++) {
            for (int j = n2; j>=1; j--) {
                if (text1[i - 1] == text2[j - 1]) {
                    prev[j] = prev[j] + prev[j - 1];
                } 
                else {
                    continue;
                }
            }
        }

        return prev[n2];
    }
};
















// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         return f(s, t);
//     }

//     int f(const string& text1, const string& text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
//         vector<double> prev(n2+1,0),curr(n2+1,0);
//         prev[0]=curr[0]=1;
//         for (int i = 1; i <= n1; i++) {
//             for (int j = 1; j <= n2; j++) {
//                 if (text1[i - 1] == text2[j - 1]) {
//                     curr[j] = prev[j] + prev[j - 1];
//                 } 
//                 else {
//                     curr[j] = prev[j];
//                 }
//             }
//             prev = curr;
//         }

//         return prev[n2];
//     }
// };
