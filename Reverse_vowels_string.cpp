#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to check if a character is a vowel
    bool check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    // Function to reverse the vowels in a string
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (check(s[i]) && check(s[j])) {
                swap(s[i++], s[j--]);
            } else if (!check(s[i]) && check(s[j])) {
                i++;
            } else if (check(s[i]) && !check(s[j])) {
                j--;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Test cases
    string test1 = "hello"; // Expected output: "holle"
    string test2 = "leetcode"; // Expected output: "leotcede"
    string test3 = "aA"; // Expected output: "Aa"

    cout << "Original: " << test1 << ", Reversed Vowels: " << sol.reverseVowels(test1) << endl;
    cout << "Original: " << test2 << ", Reversed Vowels: " << sol.reverseVowels(test2) << endl;
    cout << "Original: " << test3 << ", Reversed Vowels: " << sol.reverseVowels(test3) << endl;

    return 0;
}
