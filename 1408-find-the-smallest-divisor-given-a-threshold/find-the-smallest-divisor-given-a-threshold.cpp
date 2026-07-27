class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int res = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long total = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                total += (nums[i] + mid - 1) / mid;
                if (total > threshold) {
                    break;
                }
            }
            if (total <= threshold) {
                end = mid - 1;
                res = mid;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }
};