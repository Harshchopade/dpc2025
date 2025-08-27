#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        int start = 0, maxLen = 1;
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expandAroundCenter(i, i);

            // Even length palindrome
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    
    // Test cases
    cout << sol.longestPalindrome("babad") << endl; 
    cout << sol.longestPalindrome("cbbd") << endl;  

    return 0;
}
