class Solution {
public:
    int tribonacci(int n) {
        int t1 =0,t2=1,t3=1;
        if(n==0){
            return t1;
        }
        for(int i=3;i<=n;i++){
            int temp = t2;
            t3 += t2+t1;
            t2 = t3 - t2 - t1;
            t1 = temp;
        }
        return t3;
    }
};