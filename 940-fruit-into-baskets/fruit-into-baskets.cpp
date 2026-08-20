/*class Solution {
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
};*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, maxLen = 0;
        int fruit1 = fruits[0], fruit2 = -1;
        int lastFruit = fruits[0], lastPos = 0;

        for (int right = 0; right < fruits.size(); right++) {

            if (fruit2 == -1 && fruits[right] != fruit1) {
                fruit2 = fruits[right];
            }
            else if (fruits[right] != fruit1 &&
                     fruits[right] != fruit2) {

                left = lastPos;
                fruit1 = lastFruit;
                fruit2 = fruits[right];
            }

            if (fruits[right] != lastFruit) {
                lastFruit = fruits[right];
                lastPos = right;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};