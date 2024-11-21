class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int start = 0, maxLength = 1;
        for (int i = 0; i < n; ++i) {
            int low = i, high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                int currentLength = high - low + 1;
                if (currentLength > maxLength) {
                    start = low;
                    maxLength = currentLength;
                }
                --low;
                ++high;
            }
            low = i, high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                int currentLength = high - low + 1;
                if (currentLength > maxLength) {
                    start = low;
                    maxLength = currentLength;
                }
                --low;
                ++high;
            }
        }
        return s.substr(start, maxLength);
    }
};