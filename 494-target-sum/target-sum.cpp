class Solution {
  public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum =0;
    int n = nums.size();
      for(int i=0;i<n;i++){
        sum+= nums[i];
      }
      int x = (sum-target)/2;
      if (abs(target) > sum) return 0;
      if ((sum - target) % 2 != 0) return 0;

      return f(nums,x,n);
 }
 int f(vector<int>& arr,int x,int n){
    vector<int> prev(x+1,0),curr(x+1,0);
    if(arr[0] == 0)
      prev[0] = 2;
    else {
      prev[0] = 1;
      if(arr[0] <= x)
        prev[arr[0]] = 1;
        }
    for(int i =1;i<n;i++){
      for(int j=0;j<=x;j++){
        int ntake = prev[j];
        int take =0;
        if(j>=arr[i]){
          take = prev[j-arr[i]];
        }
        curr[j] = take + ntake;
      }
      prev = curr;
    }
    return prev[x];
  }
};


//Memoization
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum =0;
//         for(auto i:nums){
//             sum+=i;
//         }
//         vector<vector<int>> dp(nums.size(), vector<int>(2*sum + 1, -1));
//         int ans = f(nums.size() - 1, nums, target, dp,sum);
//         return ans;
//     }
//     int f(int index, vector<int>& nums, int target, vector<vector<int>>& dp,int sum) {

//         if (target < -sum || target > sum) return 0;

//         if (index == 0) {
//             if(nums[0] == 0 && target == 0) return 2;
//             else if (target == nums[0] || target == -nums[0]) {
//                 return 1;
//             } else {
//                 return 0;
//             }
//         }
//         if (dp[index][target+sum] != -1)
//             return dp[index][target+sum];
//         int n = f(index - 1, nums, target + nums[index], dp,sum);
//         int p = f(index - 1, nums, target - nums[index], dp,sum);
//         return dp[index][target+sum] = n + p;
//     };
// };
