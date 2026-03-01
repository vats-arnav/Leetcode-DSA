class Solution {
public:
    int maxProfit(int k,vector<int>& prices) { return f(k,prices); }

    int f(int z,vector<int>& prices) {
        int n = prices.size();
        long profit;
        vector<vector<long>> curr(2, vector<long>(z+1,0));
        vector<vector<long>> prev(2, vector<long>(z+1,0));
        for(int k = 1; k <= z; k++) {
            prev[1][k] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= z; k++) {
                    if (j == 0) {
                        profit =
                            max(prev[0][k], +prices[i] + prev[1][k]);
                    }
                    if (j == 1) {
                        profit =
                            max(prev[1][k], -prices[i] + prev[0][k-1]);
                    }

                    curr[j][k] = profit;
                }
            }
            prev = curr;
        }
        return (int)prev[0][z];
    }
};
















// class Solution {
// public:
//     int maxProfit(int k,vector<int>& prices) { return f(k,prices); }

//     int f(int z,vector<int>& prices) {
//         int n = prices.size();
//         long profit;
//         vector<vector<vector<long>>> dp(n, vector<vector<long>>(2,
//         vector<long>(z+1, 0))); for(int k = 1; k <= z; k++) {
//             dp[0][1][k] = -prices[0];
//         }
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j <= 1; j++) {
//                 for (int k = 1; k <= z; k++) {
//                     if (j == 0) {
//                         profit =
//                             max(dp[i - 1][0][k], +prices[i] + dp[i -
//                             1][1][k]);
//                     }
//                     if (j == 1) {
//                         profit =
//                             max(dp[i - 1][1][k], -prices[i] + dp[i -
//                             1][0][k-1]);
//                     }

//                     dp[i][j][k] = profit;
//                 }
//             }
//         }
//         return (int)dp[n - 1][0][z];
//     }
// };













// class Solution {
// public:
//     int maxProfit(vector<int>& prices) { return f(prices); }

//     int f(vector<int>& prices) {
//         int n = prices.size();
//         long profit;
//         vector<vector<vector<long>>> dp(n, vector<vector<long>>(2,
//         vector<long>(3, 0))); for(int k = 1; k <= 2; k++) {
//             dp[0][1][k] = -prices[0];
//         }
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j <= 1; j++) {
//                 for (int k = 1; k <= 2; k++) {
//                     if (j == 0) {
//                         profit =
//                             max(dp[i - 1][0][k], +prices[i] + dp[i -
//                             1][1][k]);
//                     }
//                     if (j == 1) {
//                         profit =
//                             max(dp[i - 1][1][k], -prices[i] + dp[i -
//                             1][0][k-1]);
//                     }

//                     dp[i][j][k] = profit;
//                 }
//             }
//         }
//         return (int)dp[n - 1][0][2];
//     }
// };














// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//                 int n = prices.size();
//                 vector<vector<vector<long>>> dp(n, vector<vector<long>>(2,
//                 vector<long>(k+1,-1)));

//             if (n == 0) {
//                 return 0;
//             }

//             long ans = getAns(prices, 0, 0, n, dp,k);
//             return ans;
//     }

//     long getAns(vector<int>& prices, int ind, int buy, int n,
//                 vector<vector<vector<long>>>& dp, int cap) {
//         if (cap == 0)
//             return 0;
//         if (ind == n) {
//             return 0;
//         }

//         if (dp[ind][buy][cap] != -1) {
//             return dp[ind][buy][cap];
//         }

//         long profit = 0;

//         if (buy == 0) {
//             profit = max(0 + getAns(prices, ind + 1, 0, n, dp, cap),
//                          -prices[ind] + getAns(prices, ind + 1, 1, n, dp, cap));
//         }

//         if (buy == 1) {
//             profit =
//                 max(0 + getAns(prices, ind + 1, 1, n, dp, cap),
//                     prices[ind] + getAns(prices, ind + 1, 0, n, dp, cap - 1));
//         }

//         return dp[ind][buy][cap] = profit;
//     }
// };


