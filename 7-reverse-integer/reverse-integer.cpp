class Solution {
public:
    int reverse(int x) {
        int n = x;
        long int rev = 0;
        int rem = 0;
        while (n) {
            rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0;
            }
        }
        return rev;
    }
};