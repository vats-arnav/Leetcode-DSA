class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return f(prices);
    }

    int f(vector<int>& prices){
        int n = prices.size();
        long profit;
        vector<vector<long>> dp(n+1,vector<long>(2,-1));
        dp[n][0] = dp[n][1] =0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                   profit = max(dp[i+1][0],-prices[i] + dp[i+1][1]);
                }
                if(j==1){
                    profit = max(dp[i+1][1],+prices[i] + dp[i+1][0]);
                }

                dp[i][j] = profit;
            }
        }
        return (int)dp[0][0];
    }
};