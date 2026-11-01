class Solution {
    //circular array concept , light pole?
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(), -1);
        stack<int> s;
        for (int i = nums.size()*2 - 1; i >= 0; --i){
            while (!s.empty() && nums[i % nums.size()] >= s.top()) {
                s.pop();
            }
            if (!s.empty()) {
                nge[i % nums.size()] = s.top();
            }
            s.push(nums[i % nums.size()]);
        }
        return nge;
    }
};