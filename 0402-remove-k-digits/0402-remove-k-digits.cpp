class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
         while(result.size() != 0 && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        if(result.empty()) return "0";
        return result;
    }
};