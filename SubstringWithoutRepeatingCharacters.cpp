#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> hash;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while (right < n) {
            // If the character is completely new or the previous occurrence is not in our window
            if (hash.find(s[right]) == hash.end() || hash[s[right]] < left) {
                hash[s[right]] = right;
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            // We update the window to go to the position where there are no repeating occurrences of any character.
            else {
                left = hash[s[right]] + 1;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}
