class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return f(prices);
    }

    int f(vector<int>& prices){
        int n = prices.size();
        long profit;
        vector<long> prev(2,-1),curr(2,-1);
        prev[0]=0;
        prev[1]= -prices[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=1;j++){
                if(j==0){
                   profit = max(prev[0],+prices[i] + prev[1]);
                }
                if(j==1){
                    profit = max(prev[1],-prices[i] + prev[0]);
                }

                prev[j] = profit;
            }
            //prev = curr;
        }
        return (int)prev[0];
    }
};












// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         return f(prices);
//     }

//     int f(vector<int>& prices){
//         int n = prices.size();
//         long profit;
//         vector<vector<long>> dp(n,vector<long>(2,-1));
//         dp[0][0]=0;
//         dp[0][1]= -prices[0];
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=1;j++){
//                 if(j==0){
//                    profit = max(dp[i-1][0],+prices[i] + dp[i-1][1]);
//                 }
//                 if(j==1){
//                     profit = max(dp[i-1][1],-prices[i] + dp[i-1][0]);
//                 }

//                 dp[i][j] = profit;
//             }
//         }
//         return (int)dp[n-1][0];
//     }
// };