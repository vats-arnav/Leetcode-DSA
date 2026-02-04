class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return back(0,nums,0);
    }

    int back(int index, vector<int>& nums, int xr) {
        if(index==nums.size()){
            return xr;
        }
        int x = nums[index];
        int take =back(index+1, nums,xr^x );
        int ntake =back(index+1, nums, xr);
        return take+ntake;
    }
};