class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for(int n:nums){
            if(dup.find(n)!=dup.end()) return true;
            dup.insert(n);
        }
        return false;
    }
};