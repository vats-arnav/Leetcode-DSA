class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int x=0,y=1;
        vector<int> ans(nums.size());
        for(auto i:nums){
            if(i>0){
                ans[x] = i;
                x+=2;
            }
            else{
                ans[y] = i;
                y+=2;
            }
        }
    return ans;
    }
};



/* class Solution {
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
};*/