class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int val =-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i+1]>nums[i]){
                val =i;
                break;
            }
        }
        if(val==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for (int i = n; i > val; i--) {
            if (nums[i] > nums[val]) {
                swap(nums[i], nums[val]);
                break;
            }
        }
        reverse(nums.begin() + val+1, nums.end());
    }
};