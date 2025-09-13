class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dup;
        unordered_set<int> cnt;

        for (int num : nums) {
            if (cnt.count(num)) {
                dup.push_back(num);
            } else {
                cnt.insert(num);
            }
        }
        return dup;
    }
};