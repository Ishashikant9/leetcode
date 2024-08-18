#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return t[n]; // Return the last character in t if no mismatch is found
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "abcd";
    string t1 = "abcde";
    char result1 = sol.findTheDifference(s1, t1); // Expected output: 'e'
    cout << "The extra character is: " << result1 << endl;

    // Test case 2
    string s2 = "abcde";
    string t2 = "abcfde";
    char result2 = sol.findTheDifference(s2, t2); // Expected output: 'f'
    cout << "The extra character is: " << result2 << endl;

    // Test case 3
    string s3 = "";
    string t3 = "y";
    char result3 = sol.findTheDifference(s3, t3); // Expected output: 'y'
    cout << "The extra character is: " << result3 << endl;

    return 0;
}
