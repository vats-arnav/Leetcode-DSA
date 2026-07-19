class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cntx = 0, cnty = 0, x, y;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (cntx == 0 && nums[i] != y) {
                x = nums[i];
                cntx = 1;
            } else if (cnty == 0 && nums[i] != x) {
                y = nums[i];
                cnty = 1;
            } else if (nums[i] == x) {
                cntx++;
            } else if (nums[i] == y) {
                cnty++;
            } else {
                cnty--;
                cntx--;
            }
        }
        cntx = 0;
        cnty = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                cntx++;
            }
            if (nums[i] == y) {
                cnty++;
            }
        }
        int mini = n/3 + 1;
        if (cntx >= mini) {
            res.push_back(x);
        }
        if (cnty >= mini && y!=x) {
            res.push_back(y);
        }

        return res;
    }
};

/*class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ans;
        vector<int> val;
        for (int i = 0; i < n; i++) {
            ans[nums[i]]++;
        }

        for (auto x = ans.begin(); x != ans.end(); x++) {
            if (x->second > (n / 3)) {
                val.push_back(x->first);
            }
        }

        return val;
    }
};

*/