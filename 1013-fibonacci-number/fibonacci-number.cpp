// class Solution {
// public:
//     int fib(int n) {
//         if(n==0){
//             return 0;
//         }
//         if(n==1){
//             return 1;
//         }
//         return fib(n-1) + fib(n-2);
//     }
// };

class Solution {
public:
    int fib(int n) {
        int prev1 = 0, prev2 = 1, curr;
        if (n <= 0)
            return n;
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};