#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int n = s.size();
        
        // Count occurrences of each character
        for (int i = 0; i < n; i++) {
            map[s[i]]++;
        }
        
        // Find the first unique character
        for (int i = 0; i < n; i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        
        return -1; // Return -1 if no unique character exists
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "leetcode";
    int result1 = sol.firstUniqChar(s1); // Expected output: 0
    cout << "First unique character index in \"" << s1 << "\": " << result1 << endl;

    // Test case 2
    string s2 = "loveleetcode";
    int result2 = sol.firstUniqChar(s2); // Expected output: 2
    cout << "First unique character index in \"" << s2 << "\": " << result2 << endl;

    // Test case 3
    string s3 = "aabb";
    int result3 = sol.firstUniqChar(s3); // Expected output: -1
    cout << "First unique character index in \"" << s3 << "\": " << result3 << endl;

    return 0;
}
