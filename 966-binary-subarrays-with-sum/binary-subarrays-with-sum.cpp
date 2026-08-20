class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        int l = 0;
        int sum = 0;
        int count = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > k) {
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
};