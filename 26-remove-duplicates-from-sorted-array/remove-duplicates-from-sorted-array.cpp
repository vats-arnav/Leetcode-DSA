class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int count = 0;
        if(nums.size()==1) return 1;
        while (ptr1 < n && ptr2 < n) {
            int val = nums[ptr2];
            while (ptr2<n && val == nums[ptr2]) {
                ptr2++;
            }
            count++;
            nums[ptr1] = val;
            ptr1++;
        }
        return count;
    }
    };