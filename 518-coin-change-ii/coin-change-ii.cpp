 class Solution {
 public:
     int change(int amount, vector<int>& coins) {
         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
         int ans = f(coins.size()-1,coins,amount,dp);
         return ans;
     }

    int f(int index,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(index==0){
            if(amount%coins[index]==0){
                return 1;
            }
            else return 0;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int ntake = f(index-1,coins,amount,dp);
        int take = 0;
        if(amount>= coins[index]){
            take = f(index,coins,amount-coins[index],dp);
        }

        return dp[index][amount] = take+ntake;
    
}};

/*
class Solution {
public:
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
    int change(int amount, vector<int>& coins) {
        int ans = f(0, coins, amount);
        return ans >= 1e9 ? -1 : ans;
    }
};*/