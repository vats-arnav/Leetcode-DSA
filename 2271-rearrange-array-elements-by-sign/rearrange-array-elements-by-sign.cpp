class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arrp;
        vector<int> arrn;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                arrp.push_back(nums[i]);
            }
            else{
                arrn.push_back(nums[i]);
            }
        }
        for(int i=0;i<arrp.size();i++){
            ans.push_back(arrp[i]);
            ans.push_back(arrn[i]);
        }

        return ans;
    }
};