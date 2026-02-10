class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> data;
        rec(1, n, k, result, data);
        return result;
    }

    void rec(int index, int n, int k, vector<vector<int>>& result,vector<int>& data) {
        if (data.size() == k) {
            result.push_back(data);
            return;
        }
        for (int i = index; i <= n; i++) {
            data.push_back(i);
            rec(i+1, n, k, result, data);
            data.pop_back();
        }
    }
};