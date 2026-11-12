class Solution {
public:
//classic sliding window
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        int maxLen = 0;
        unordered_map<int, int> basket;
        while (r < fruits.size()) {
            basket[fruits[r]]++; 
            if (basket.size() > 2) {
                basket[fruits[l]]--;
            if (basket[fruits[l]] == 0) {
                    basket.erase(fruits[l]);
                }
                l++;
            }
            if (basket.size() <= 2) {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};