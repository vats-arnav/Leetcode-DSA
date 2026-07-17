class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> arr;
        arr[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r = sum-k;
            if (arr.find(r) != arr.end()) {
                count += arr[r];
            }
            arr[sum]++;
        }
        return count;
    }
};