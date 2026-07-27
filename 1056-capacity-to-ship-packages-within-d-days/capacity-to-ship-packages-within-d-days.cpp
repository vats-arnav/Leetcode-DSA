class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int ans = check(weights, mid);

            if (ans <= days) {
                end = mid-1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

    int check(vector<int>& weights, int capacity) {
        int days = 1;
        int cload = 0;

        for (int x : weights) {
            if (cload + x > capacity) {
                days++;
                cload = x;
            } else {
                cload += x;
            }
        }

        return days;
    }
};