class Solution {
public:
    void generate(int n, string x, vector<string>& ans) {
        if (x.size() == n * 2) {
            int balance = 0;
            for (char c : x) {
                if (c == '(')
                    balance++;
                else
                    balance--;
                if (balance < 0)
                    return;
            }
            if (balance == 0)
                ans.push_back(x);
            return;
        }

        generate(n, x + "(", ans);
        generate(n, x + ")", ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate(n, "", ans);
        return ans;
    }
};