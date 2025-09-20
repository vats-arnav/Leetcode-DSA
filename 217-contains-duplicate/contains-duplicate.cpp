class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> dup;
        for(int n:nums){
            if(dup.count(n)) return true;
            dup[n] =1;
        }
        return false;
    }
};