class Solution {
public:
    int first(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                l = mid;
                end = mid - 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return l;
    }
    int last(vector<int>& nums, int target) {
        int n = nums.size();
        int u = -1;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                u = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return u;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int f = first(nums, target);
        if (f == -1) {
            return {-1, -1};
        }
        int l = last(nums, target);
        return {f, l};
    }
};