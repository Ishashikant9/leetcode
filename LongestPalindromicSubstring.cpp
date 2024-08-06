#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "babad"; // Expected output: "bab" or "aba"
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s1) << endl;

    // Test case 2
    string s2 = "cbbd"; // Expected output: "bb"
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s2) << endl;


    return 0;
}
