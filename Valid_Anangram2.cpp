#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << (sol.isAnagram(s1, t1) ? "True" : "False") << endl; // Expected output: True

    string s2 = "rat";
    string t2 = "car";
    cout << (sol.isAnagram(s2, t2) ? "True" : "False") << endl; // Expected output: False

    return 0;
}
