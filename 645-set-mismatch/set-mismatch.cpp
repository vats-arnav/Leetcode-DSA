class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        for (int i = 0; i < n; i++) {
            xr = xr ^ nums[i];
            xr = xr ^ (i + 1);
        }

        int bit = 0;
        while (1) {
            if ((xr & (1 << bit)) != 0) {
                break;
            }
            bit++;
        }
        int z = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1 << bit) != 0) {
                one = one ^ nums[i];
            } else {
                z = z ^ nums[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            if ((i & 1 << bit) != 0) {
                one = one ^ i;
            } else {
                z = z ^ i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == one)
                cnt++;
        }
        if (cnt == 2) {
            return {one, z};
        } else {
            return {z, one};
        }
    }
};