// SO
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int ans = f(0, coins, amount);
        return ans >= 1e9 ? -1 : ans;
    }

    int f(int index, vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, 1e9), curr(amount + 1, 1e9);
        if (index == 0) {
            for (int i = 0; i <= amount; i++) {
                if (i % coins[0] == 0) {
                    prev[i] = i / coins[0];
                } else {
                    prev[i] = 1e9;
                }
            }
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                int ntake = 0 + prev[j];
                int take = INT_MAX;
                if (j >= coins[i]) {
                    take = 1 + curr[j - coins[i]];
                }
                curr[j] = min(take, ntake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};

// Tabulation
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 1e9));
//         int ans = f(0, coins, amount, dp);
//         return ans >= 1e9 ? -1 : ans;
//     }

//     int f(int index, vector<int>& coins, int amount, vector<vector<int>>& dp)
//     {

//         if (index == 0) {
//             for (int i = 0; i <= amount; i++) {
//                 if (i % coins[0] == 0) {
//                     dp[0][i] = i / coins[0];
//                 } else {
//                     dp[0][i] = 1e9;
//                 }
//             }
//         }

//         for (int i = 1; i < coins.size(); i++) {
//             for (int j = 0; j <= amount; j++) {
//                 int ntake = 0 + dp[i - 1][j];
//                 int take = INT_MAX;
//                 if (j >= coins[i]) {
//                     take = 1 + dp[i][j - coins[i]];
//                 }
//                 dp[i][j] = min(take, ntake);
//             }
//         }
//         return dp[coins.size() - 1][amount];
//     }
// };

// Memoization
//  class Solution {
//  public:
//      int coinChange(vector<int>& coins, int amount) {
//          vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e9));
//          int ans = f(coins.size()-1,coins,amount,dp);
//          return ans>= 1e9 ? -1 : ans;
//      }

//     int f(int index,vector<int>& coins, int amount,vector<vector<int>>& dp){

//         if(index==0){
//             if(amount%coins[index]==0){
//                 return amount/coins[index];
//             }
//             else{
//                 return 1e9;
//             }
//         }
//         if(dp[index][amount]!=1e9)
//             return dp[index][amount];
//         int ntake = 0 + f(index-1,coins,amount,dp);
//         int take = INT_MAX;
//         if(amount>= coins[index]){
//             take = 1 + f(index,coins,amount-coins[index],dp);
//         }

//         return dp[index][amount] = min(take,ntake);
//     }
// };