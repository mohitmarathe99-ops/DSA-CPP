class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int longestLength = 0;
        for (int value : values) {
            if (values.count(value - 1)) {
                continue;
            }
            int currentLength = 1;
            int nextValue = value + 1;
            while (values.count(nextValue)) {
                currentLength++;
                nextValue++;
            }
 
            longestLength = max(longestLength, currentLength);
        }
 
        return longestLength;
    }
    
};