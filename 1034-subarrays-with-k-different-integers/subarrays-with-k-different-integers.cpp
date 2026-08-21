class Solution {
public:
    int count(vector<int>& nums, int k) {
        int val = 0;
        int n = nums.size();
        int l = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            if (freq[nums[i]] == 0) {
                k--;
            }
            freq[nums[i]]++;
            while (k < 0) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    k++;
                l++;
            }
            val += i - l + 1;
        }
        return val;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k - 1);
    }
};