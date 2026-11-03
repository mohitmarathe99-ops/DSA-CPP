class Solution {
    //modulo 1e9+7 not told 
    private:
    vector<int> findnse(vector<int>& nums){
        int n = nums.size();
        vector<int> nse(n,n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            nse[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>& nums){
        int n = nums.size();
        vector<int> pse(n,-1);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            pse[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> findnge(vector<int>& nums){
        int n = nums.size();
        vector<int> nge(n,n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            nge[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findpge(vector<int>& nums){
        int n = nums.size();
        vector<int> pge(n,-1);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            pge[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        
     vector<int> nse = findnse(nums);
     vector<int> pse = findpse(nums);
     vector<int> nge = findnge(nums);
     vector<int> pge = findpge(nums);
        
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long left1 = i - pge[i];
            long long right1 = nge[i] - i;
            
            ans += (left1 * right1 * nums[i]) - (left * right * nums[i]);
        }
        return ans;
    
    }

};