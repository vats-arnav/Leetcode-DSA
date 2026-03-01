class Solution {
public:
    int maxProfit(vector<int>& prices,int fees) {
        return f(prices,fees);
    }

    int f(vector<int>& prices,int fees){
        int n = prices.size();
        long profit;
        vector<long> prev(2,-1),curr(2,-1);
        prev[0]=0;
        prev[1]= -prices[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=1;j++){
                if(j==0){
                   profit = max(prev[0],+prices[i] + prev[1]-fees);
                }
                if(j==1){
                    profit = max(prev[1],-prices[i] + prev[0]);
                }

                curr[j] = profit;
            }
            prev = curr;
        }
        return (int)prev[0];
    }
};