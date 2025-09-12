class Solution {
public:
    int subtractProductAndSum(int n) {
        int num = n;
        int sum = 0;
        int product = 1;
        while (num > 0) {
            int d = num % 10;
            sum += d;
            product *= d;
            num /= 10;
        }
        return product - sum;
    }
};