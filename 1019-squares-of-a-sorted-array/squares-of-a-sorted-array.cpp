class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pos = n - 1;
        int k = n - 1;
        vector<int> nums2(n);
        int j = 0;
        while (k >= j) {
            if (abs(nums[k]) > abs(nums[j])) {
                nums2[pos] = nums[k] * nums[k];
                k--;
            } else {
                nums2[pos] = nums[j] * nums[j];
                j++;
            }
            pos--;
        }

        return nums2;
    }
};