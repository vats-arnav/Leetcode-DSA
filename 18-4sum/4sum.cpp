class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<int> hash;
                for (int k = j + 1; k < n; k++) {
                    long long req = (long long)target - nums[i] - nums[j] - nums[k];
                    if (req < INT_MIN || req > INT_MAX)
                        continue;
                    if (hash.find((int)req) != hash.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)req};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                hash.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};