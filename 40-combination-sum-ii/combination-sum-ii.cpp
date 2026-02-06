class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        sort(candidates.begin(), candidates.end());
        calc(0, candidates, ans, nums, target, 0);
        return ans;
    }
    void calc(int index, vector<int>& candidates, vector<vector<int>>& ans,
              vector<int>& nums, int target, int sum) {   
        if (sum == target) {
            ans.push_back(nums);
            return;
            }
        for (int i = index; i < candidates.size(); i++) {

            if (sum + candidates[i]>target) {
                break;
            }
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            sum += candidates[i];
            nums.push_back(candidates[i]);
            calc(i+1, candidates, ans, nums, target, sum);
            sum -= candidates[i];
            nums.pop_back();
        }
    }


};