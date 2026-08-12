class Solution {
public:
    int hammingDistance(int start, int goal) {
        int x = start^goal;
        int count = 0;

        for(int i = 0; i < 32; i++) {
            count += (x & 1);
            x = x >> 1;
        }
        return count;
    }
};