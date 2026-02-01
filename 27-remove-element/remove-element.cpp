class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int count = 0;
        if (nums.size() == 0)
            return 0;
        while (ptr2 < n) {
            if (nums[ptr2] != val) {
                count++;
                nums[ptr1] = nums[ptr2];
                ptr1++;
            }
            ptr2++;
        }
        return count;
    }
};