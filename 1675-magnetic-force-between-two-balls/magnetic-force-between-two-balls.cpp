class Solution {
public:
    int maxDistance(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int left = 1;
        int right = arr.back() - arr.front();
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(arr, k, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    bool check(vector<int>& arr, int k, int mid) {
        int count = 1;
        int last = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= mid) {
                count++;
                last = arr[i];
            }

            if (count == k)
                return true;
        }

        return false;
    }
};