class Solution {
private:
    bool isPalindromeHelper(const string& s, int left, int right) {
        if (left >= right) {
            return true;
        }

        if (!isalnum(s[left])) {
            return isPalindromeHelper(s, left + 1, right);
        }

        if (!isalnum(s[right])) {
            return isPalindromeHelper(s, left, right - 1);
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        return isPalindromeHelper(s, left + 1, right - 1);
    }

public:
    bool isPalindrome(string s) {
        return isPalindromeHelper(s, 0, s.length() - 1);
    }
};