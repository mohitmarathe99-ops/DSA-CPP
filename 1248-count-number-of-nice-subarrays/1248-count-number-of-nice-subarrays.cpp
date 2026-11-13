class Solution {
public:
//on previous approach of containing all three characters
    int func(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0, r = 0, count = 0, sum = 0;   
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] % 2;
        }
        return func(nums, k) - func(nums, k - 1);
    }
};