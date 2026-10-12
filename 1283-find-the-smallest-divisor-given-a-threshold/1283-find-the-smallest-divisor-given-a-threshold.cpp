#include<bits/stdc++.h>
class Solution {
public:
// we ball 
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }
            if (sum > threshold) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return low;
    }
};