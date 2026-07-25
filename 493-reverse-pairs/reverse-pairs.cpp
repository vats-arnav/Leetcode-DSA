class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    int count(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2 * 1LL * (nums[right]))
                right++;
            count += right - (mid + 1);
        }
        return count;
    }
    int mergesort(vector<int>& nums, int low, int high) {
        int cnt =0;
        if (low >= high) {
            return cnt;
        }
        int mid = (low + high) / 2;
        cnt += mergesort(nums, low, mid);
        cnt += mergesort(nums, mid + 1, high);
        cnt += count(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {

        return mergesort(nums, 0, nums.size() - 1);
    }
};