class Solution {
public:
    int count(vector<int>& nums, int k) {
        int val = 0;
        int n = nums.size();
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                k--;
            }
            while (k < 0) {
                if (nums[l] % 2 != 0)
                    k++;
                l++;
            }
            val += i - l + 1;
        }
        return val;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k - 1);
    }
};