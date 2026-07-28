class Solution {
public:
    int counts(vector<int>& nums, int mid) {
        int st = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                sum = nums[i];
                st++;
            }
        }
        return st;
    }
    int splitArray(vector<int>& nums, int k) {
        if (k > nums.size())
            return -1;
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int c = counts(nums, mid);
            if (c <= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};