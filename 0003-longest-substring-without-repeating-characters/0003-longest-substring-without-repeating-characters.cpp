class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> hash(256, -1);
    int left = 0, right = 0, maxLen = 0, n = s.size();
    while (right < n) {
        if (hash[s[right]] != -1) {
            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }
        }
        int len = right - left + 1;
        maxLen = max(maxLen, len);
        hash[s[right]] = right;
        right++;
    }
    return maxLen;
}
};