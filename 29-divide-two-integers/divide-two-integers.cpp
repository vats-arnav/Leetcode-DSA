class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = dividend;
        long long b = divisor;

        bool negative = (a < 0) ^ (b < 0);

        a = abs(a);
        b = abs(b);

        long long quotient = 0;

        for (int i = 31; i >= 0; i--) {
            if ((b << i) <= a) {
                a -= (b << i);
                quotient += (1LL << i);
            }
        }

        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};