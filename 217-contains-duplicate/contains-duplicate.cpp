class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> dup;
        for(int n:nums){
            dup[n]+=1;
        }
        for(auto a:dup){
            if(a.second>1){
                return true;
            }
        }
        return false;
    }
};