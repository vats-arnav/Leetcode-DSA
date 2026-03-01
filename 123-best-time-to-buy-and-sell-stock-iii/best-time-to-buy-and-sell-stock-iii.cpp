class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(2, vector<long>(3,-1)));

    if (n == 0) {
        return 0;
    }

    long ans = getAns(prices, 0, 0, n, dp,2);
    return ans;
    }

    long getAns(vector<int>& prices, int ind, int buy, int n, vector<vector<vector<long>>> &dp,int cap) {
    if(cap==0) return 0;
    if (ind == n) {
        return 0;
    }

    if (dp[ind][buy][cap] != -1) {
        return dp[ind][buy][cap];
    }

    long profit = 0;

    if (buy == 0) { 
        profit = max(0 + getAns(prices, ind + 1, 0, n, dp,cap), -prices[ind] + getAns(prices, ind + 1, 1, n, dp,cap));
    }

    if (buy == 1) { 
        profit = max(0 + getAns(prices, ind + 1, 1, n, dp,cap), prices[ind] + getAns(prices, ind + 1, 0, n, dp,cap-1));
    }

    return dp[ind][buy][cap] = profit;
}

};



