/***class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(nums1.size());
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            int index = find(nums1.begin(), nums1.end(), nums[i]) - nums1.begin();
            if (find(nums1.begin(), nums1.end(), nums[i]) != nums1.end()) {
                if (st.empty())
                    res[index] = -1;
                else
                    res[index] = st.top();
                count++;
            }
            st.push(nums[i]);
        }
        return res;
    }
};*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        stack<int> st;
        unordered_map<int, int> next;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            next[nums[i]] = st.empty() ? -1 : st.top();

            st.push(nums[i]);
        }

        vector<int> res;

        for (int x : nums1) {
            res.push_back(next[x]);
        }

        return res;
    }
};