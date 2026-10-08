class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Mohit
             int n = nums.size();
        int low = 0, high = n - 1;
        int answer = n; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;        
    }
};