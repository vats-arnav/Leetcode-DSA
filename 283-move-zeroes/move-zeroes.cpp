class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int leftp = 0;
        int rightp = 0;
        int n = nums.size();
        while (rightp < n) {
            if (nums[rightp] != 0) {
                // swap(nums[leftp],nums[rightp]);
                nums[leftp] = nums[rightp];
                leftp++;
            }
            rightp++;
        }
        while (leftp < n) {
            nums[leftp] = 0;
            leftp++;
        }
    }
};