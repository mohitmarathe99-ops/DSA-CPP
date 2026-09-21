class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int n = nums.size();
        int zeroPosition = 0;

        for (int current = 0; current < n; current++) {
           
            if (nums[current] != 0) {
                swap(nums[current], nums[zeroPosition]);
                zeroPosition++;
            }
        }
        
    }
};