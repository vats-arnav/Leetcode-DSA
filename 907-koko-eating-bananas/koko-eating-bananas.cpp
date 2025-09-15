class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int res = end;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long total = 0;
            for (size_t i = 0; i < piles.size(); ++i) {
                total += ((long long)piles[i] + mid - 1) / mid;
                if (total > h) {
                    break;
                }
            }
            if (total <= h) {
                end = mid - 1;
                res = mid;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }
};