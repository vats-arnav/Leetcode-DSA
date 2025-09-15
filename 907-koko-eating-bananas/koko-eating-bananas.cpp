class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int res = end;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long total = 0;
            for (int bananas : piles) {
                total += (bananas + mid - 1) / mid;
                if (total > h) break;
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