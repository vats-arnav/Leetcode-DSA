class Solution {
public:
    vector<int> val(int numRows) {
        vector<int> temp;
        long long ans = 1;
        temp.push_back(1);
        for (int i = 1; i < numRows; i++) {
            ans = ans * (numRows - i);
            ans = ans / i;
            temp.push_back(ans);
        }

        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(val(i));
        }
        return ans;
    }
};

/*

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        if (numRows == 1) {
            return ans;
        }
        ans.push_back({1,1});
        if (numRows == 2) {
            return ans;
        }
        while (ans.size() != numRows) {
            vector<int> temp;
            vector<int> prev = ans.back();
            temp.push_back(1);
            for (int i = 1; i < prev.size(); i++) {
                temp.push_back(prev[i-1] + prev[i]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
*/