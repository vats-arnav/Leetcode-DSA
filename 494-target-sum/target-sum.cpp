class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(auto i:nums){
            sum+=i;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2*sum + 1, -1));
        int ans = f(nums.size() - 1, nums, target, dp,sum);
        return ans;
    }
    int f(int index, vector<int>& nums, int target, vector<vector<int>>& dp,int sum) {

        if (target < -sum || target > sum) return 0;

        if (index == 0) {
            if(nums[0] == 0 && target == 0) return 2;
            else if (target == nums[0] || target == -nums[0]) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[index][target+sum] != -1)
            return dp[index][target+sum];
        int n = f(index - 1, nums, target + nums[index], dp,sum);
        int p = f(index - 1, nums, target - nums[index], dp,sum);
        return dp[index][target+sum] = n + p;
    };
};
