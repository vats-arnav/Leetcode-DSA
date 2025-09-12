class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int k = n;
        int m=0;
        while(k!=0){
            m = (m<<1) | 1;
            k = k>>1;
        }
        return (~n)&m;
    }
};