class Solution {
public:
    double calc(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1 || x == 1) {
            return x;
        }

        if (n % 2 == 0) {
            return calc(x * x, n / 2);
        } else {
            return x * calc(x*x, n/2);
        }
    }
    double myPow(double x, int n) {
        long long num = n;
        if (n < 0) {
            return 1.0/calc(x, -1 * num);
        }

        return calc(x, num);
    }
};