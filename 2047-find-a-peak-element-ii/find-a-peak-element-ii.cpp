class Solution {
public:
    int maxr(vector<vector<int>> arr, int col) {
        int n = arr.size();
        int v = INT_MIN;
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i][col] > v) {
                v = arr[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = maxr(mat, mid);
            int left = (mid - 1) >= 0 ? mat[r][mid - 1] : -1;
            int right = (mid + 1) < m ? mat[r][mid + 1] : -1;
            if (mat[r][mid] > left && mat[r][mid] > right) {
                return {r, mid};
            } else if (left > mat[r][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};