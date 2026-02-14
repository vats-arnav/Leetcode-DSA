class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        vector<int> dp2(n);
        dp[0]=nums[0];
        if(n==1){
            return dp[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        dp[1]= max(nums[0], nums[1]);
        dp2[1] = nums[1];
        for(int i=2;i<n-1;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        for(int i=2;i<n;i++){
            dp2[i] = max(dp2[i-2]+nums[i],dp2[i-1]);
        }
        return max(dp[n-2],dp2[n-1]);
    }
};
