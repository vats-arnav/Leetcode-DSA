class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 0;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        if(1LL*m*k > bloomDay.size()){
            return -1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(bloomDay, mid, m, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
    bool possible(vector<int>& bloomDay, int mid, int m, int k) {
        int count = 0;
        int cont = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (mid >= bloomDay[i]) {
                cont++;

                if (cont == k) {
                    count++;
                    cont = 0;
                }
            } else {
                cont = 0;
            }
        }

        return count>=m;
    }
};