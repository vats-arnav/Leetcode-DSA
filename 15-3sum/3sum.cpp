class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int j = i+1;
            int k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return ans;
    }
};

/*

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            unordered_set<int> hash;
            for (int j = i + 1; j < n; j++) {
                int t = -(nums[i] + nums[j]);
                if (hash.find(t) != hash.end()) {
                    vector<int> temp = {nums[i], nums[j], t};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }

                hash.insert(nums[j]);
            }
        }

        return vector<vector<int>>(ans.begin(),ans.end());
    }
};

*/