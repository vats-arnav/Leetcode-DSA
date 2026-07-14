class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int sum =0;
        int m =INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum =0;
            }
            m = max(m,sum+nums[i]);
            sum += nums[i];
        }
    return m;
    }

};