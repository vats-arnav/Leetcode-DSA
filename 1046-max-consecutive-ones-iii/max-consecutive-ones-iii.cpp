class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int maxval = 0;
        int zeroes = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) {
                zeroes++;
            }
            if (zeroes > k) {
                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            maxval = max(r - l + 1, maxval);
        }
        return maxval;
    }
};