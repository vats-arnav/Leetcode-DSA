class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dup;
        for(int num : nums){
            num = abs(num);
            if(nums[num-1]<0){
                dup.push_back(abs(num));
            }
            nums[num-1] = nums[num-1]*-1;
        }
        return dup;

    }
};