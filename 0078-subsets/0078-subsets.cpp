class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        int n = nums.size();
        int totalSubsets = 1 << n;
        for (int i = 0; i < totalSubsets; i++) {
            vector<int> list;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    list.push_back(nums[j]);
                }
            }
            subset.push_back(list);
        }
        return subset;
    }
};