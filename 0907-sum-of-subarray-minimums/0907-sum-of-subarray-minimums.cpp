class Solution 
//jotted down , kinda makes sense remember and pay attention to test case (1,1)
{
private:
    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        long long total = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + arr[i] * left % mod * right % mod) % mod;
        }
        return total;
    }
};