class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        long long start = 1;
        long long end = *max_element(piles.begin(), piles.end());
        long long mid = 0;
        int res = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            cout << mid << endl;
            if (time(piles, mid) <= h) {
                end = mid - 1;
                res = mid;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    long long int time(vector<int>& piles, int t) {
        long long int total_hrs = 0;
        for (long long i = 0; i < piles.size(); i++) {
            long long time = ceil((double)piles[i] / t);
            total_hrs += time;
        }
        // cout<<total_hrs<<endl;
        return total_hrs;
    }
};