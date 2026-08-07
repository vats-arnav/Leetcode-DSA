/*
class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        long long ans = 0;
        int n = s.size();
        if (s.length() == 0)
            return 0;
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }
            i++;
        }

        return (int)(sign * ans);
    }
};
*/
class Solution {
public:
    int helper(const string& s, int i, long long num, int sign) {
        if (i >= s.size() || !isdigit(s[i]))
            return (int)(sign * num);

        num = num * 10 + (s[i] - '0');
        if (sign * num <= INT_MIN)
            return INT_MIN;
        if (sign * num >= INT_MAX)
            return INT_MAX;

        return helper(s, i + 1, num, sign);
    }
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;

        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return helper(s, i, 0, sign);
    }
};