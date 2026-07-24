class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum =
                        (long long) nums[i] + nums[j] + nums[r] + nums[l];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        r--;
                        l++;

                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};

/*

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<int> hash;
                for (int k = j + 1; k < n; k++) {
                    long long req = (long long)target - nums[i] - nums[j] -
nums[k]; if (req < INT_MIN || req > INT_MAX) continue; if (hash.find((int)req)
!= hash.end()) { vector<int> temp = {nums[i], nums[j], nums[k], (int)req};
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

*/