class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> data;
        sort(nums.begin(),nums.end());
        rec(0,result,data,nums);
        return result;
    }

    void rec(int index,vector<vector<int>>& result,vector<int> &data,vector<int> &nums){
        result.push_back(data);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            data.push_back(nums[i]);
            rec(i+1,result,data,nums);
            data.pop_back();
        }

    }
};