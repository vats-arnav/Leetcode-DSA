class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0;
        for (int start = 0; count < n; start++) {
            int curr = start;
            int prev = nums[start];
            do {
                int next = (curr + k) % n;
                swap(prev, nums[next]);
                curr = next;
                count++;
            } while (start != curr);
        }
    }
};

/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};*/