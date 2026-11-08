class Solution {
public:
    bool canJump(vector<int>& nums) {
      int maxfind = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (i>maxfind) return false;
        if (nums[i] + i > maxfind)
        maxfind = nums[i] + i;
      }
      return true;
        
    }
};