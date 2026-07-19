class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ans;
        vector<int> val;
        for (int i = 0; i < n; i++) {
            ans[nums[i]]++;
        }

        for (auto x = ans.begin(); x != ans.end(); x++) {
            if (x->second > (n / 3)) {
                val.push_back(x->first);
            }
        }

        return val;
    }
};