class Solution {
public:
    bool f(vector<int>& nums,vector<vector<int>>& dp,int target){
        int n = nums.size();
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool ntake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i]){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take | ntake;
            }
        }

        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1));
        if(sum%2!=0){
            return false;
        }
        else{
            return f(nums,dp,sum/2);
        }
    }
};

//SO
// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;
// bool f(vector<int> &num,int target,vector<bool> &dp){
//     int n = num.size();
//     dp[0] = true;
//     for(int i =1;i<n;i++){
//         vector<bool> temp(target+1,false);
//         temp[0] = true;
//         for(int j =1;j<=target;j++){
//             bool nottake = dp[j];
//             bool take = false;
//             if(j>= num[i]){
//                 take = dp[j-num[i]];
//             }
//             temp[j] = take | nottake;
//         }
//         dp = temp;
//     }
//     return dp[target];
// }

// int main() {
//     vector<int> num = {1,4,5,2,9};
//     int target = 7;
//     vector<bool> dp(target+1,false);
//     cout<<f(num,target,dp);
//     return 0;
// }

//Recursion
// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;
// bool f(vector<int> &num,int target,int index,vector<vector<int>> &dp){
//     if(target==0){
//         return true;
//     }
//     if(index==0){ return target == num[0];}
//     if(dp[index][target]!=-1){
//         return dp[index][target];
//     }
//     bool take = false;
//     bool nottake = f(num,target,index-1,dp);
//     if(num[index] <= target){
//         take = f(num,target-num[index],index-1,dp);}
    
//     return dp[index][target] = take || nottake;
// }

// int main() {
//     vector<int> num = {1,4,5,2,9};
//     vector<vector<int>> dp(num.size(), vector<int>(target+1, -1));
//     cout<<f(num,2,num.size()-1,dp);
//     return 0;
// }
