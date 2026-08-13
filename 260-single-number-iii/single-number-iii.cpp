class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) {
            return nums;
        }
        long XOR = 0;

        for (int i = 0; i < n; i++) {

            XOR = XOR ^ nums[i];
        }
        int XOR1 = 0, XOR2 = 0;
        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        for (int i = 0; i < n; i++) {
            if (nums[i] & rightmost) {
                XOR1 = XOR1 ^ nums[i];
            } else {
                XOR2 = XOR2 ^ nums[i];
            }
        }
        if (XOR1 < XOR2)
            return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};
