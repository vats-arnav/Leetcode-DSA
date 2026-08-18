class Solution {
public:
    string removeKdigits(string nums, int k) {
        if (nums.size() == k) {
            return "0";
        }
        if (k == 0) {
            return nums;
        }
        stack<char> st;
        for (int i = 0; i < nums.size(); i++) {

            char digit = nums[i];
            while (!st.empty() && k > 0 && st.top() > digit) {

                st.pop();
                k--;
            }
            st.push(digit);
        }

        while (!st.empty() && k > 0) {

            st.pop();
            k--;
        }

        string res = "";

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        while (res.size() > 0 && res.back() == '0') {
            res.pop_back();
        }
        if(res.empty()) return "0";
        reverse(res.begin(), res.end());

        return res;
    }
};