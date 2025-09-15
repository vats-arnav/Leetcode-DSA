class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int start = 0;
        int end = (r * c) - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int r_index = mid / c;
            int c_index = mid % c;
            if (matrix[r_index][c_index] == target) {
                return true;
            } else if (matrix[r_index][c_index] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};