#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }

        if (m1 == m2) {
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
