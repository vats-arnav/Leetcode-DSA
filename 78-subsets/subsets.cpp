class Solution{
    public:
    vector<vector<int>> subsets(vector<int>& nums) {  
        int n = nums.size();
        int subset = 1<<n;
        vector<vector<int>> result;
        for(int i=0;i<subset;i++){
            vector<int> ans;
            for(int j =0;j<n;j++){
                if(i & (1<<j)){
                    ans.push_back(nums[j]);
                }
            }
            result.push_back(ans);
        }
        return result;
    } 
};



// class Solution {
// public:
//     vector<vector<int>> result;
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> current;
//         back(0, nums, current);
//         return result;
//     }

//     void back(int index, vector<int>& nums, vector<int>& current) {
//         result.push_back(current);
//         for (int i = index; i < nums.size(); i++) {
//             current.push_back(nums[i]);
//             back(i + 1, nums, current);
//             current.pop_back();
//         }
//     }
// };