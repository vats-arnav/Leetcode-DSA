class Solution {
public:
    int mySqrt(int x) {
        int end = x;
        int start = 0;
        int res = 0;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if((long long)mid*mid > x){
                end = mid-1;
            }
            else if((long long)mid*mid<x){
                start = mid+1;
                res = mid;
            }
            else{
            return mid;
        }
    }
    return res;
}
};