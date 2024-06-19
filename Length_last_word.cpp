#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') len++;
            else if (len != 0) break;
        }
        return len;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "Hello World";
    string test2 = "   fly me   to   the moon  ";
    string test3 = "luffy is still joyboy";
    string test4 = "a";
    string test5 = "    ";
    string test6 = "b   a    ";
    
    // Printing the results
    cout << "Length of last word in \"" << test1 << "\": " << solution.lengthOfLastWord(test1) << endl;
    cout << "Length of last word in \"" << test2 << "\": " << solution.lengthOfLastWord(test2) << endl;
    cout << "Length of last word in \"" << test3 << "\": " << solution.lengthOfLastWord(test3) << endl;
    cout << "Length of last word in \"" << test4 << "\": " << solution.lengthOfLastWord(test4) << endl;
    cout << "Length of last word in \"" << test5 << "\": " << solution.lengthOfLastWord(test5) << endl;
    cout << "Length of last word in \"" << test6 << "\": " << solution.lengthOfLastWord(test6) << endl;

    return 0;
}