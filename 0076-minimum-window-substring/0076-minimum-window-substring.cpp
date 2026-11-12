class Solution {
public:
//intuitive yet not struck
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0, r = 0;
        int minLen = 1e9;
        int sIndex = -1;
        int count = 0;
        if (n < m) return "";
        int hash[256] = {0};
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        while (r < n) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;
            while (count == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};