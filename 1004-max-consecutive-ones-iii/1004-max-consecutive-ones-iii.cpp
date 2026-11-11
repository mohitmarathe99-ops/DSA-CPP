#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int zeroCount = 0;
        int n = nums.size();
        for (right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            if (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            if (zeroCount <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};