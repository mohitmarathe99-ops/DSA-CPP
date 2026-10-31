class Solution {
    //subset thing and map loved it
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        stack<int> st;
        for (int i = nums2.size() - 1;i>=0;i--){
            int current = nums2[i];
            while(!st.empty() && st.top() <= current) {
                st.pop();
            } 
            if(st.empty()) {
                nge[current] = -1;
            }
            else{
                nge[current] = st.top();
            }
            st.push(current);
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nge[num]);
        }
        return ans;
        
    }
};