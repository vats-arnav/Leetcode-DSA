class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int maxval = 0;
        unordered_map<int, int> basket;
        for (int r = 0; r < fruits.size(); r++) {
            basket[fruits[r]]++;
            if (basket.size() > 2) {
                basket[fruits[l]]--;
                if (basket[fruits[l]] == 0) {
                    basket.erase(fruits[l]);
                }
                l++;
            }
            maxval = max(r - l + 1, maxval);
        }
        return maxval;
    }
};