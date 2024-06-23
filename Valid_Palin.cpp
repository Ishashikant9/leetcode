#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        std::string res = ""; // this string contain only alpha numeric 
      
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if ((ch >= '0') && (ch <= '9'))
                res += ch;
            else if ((ch >= 'a') && (ch <= 'z'))
                res += ch;
        }
        int i = 0;
        int j = res.size() - 1;
        while (i <= j) {
            if (res[i] != res[j]) {
                return false;
            }
            if (res[i] == res[j]) {
                i++;
                j--;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    bool result = sol.isPalindrome(input);
    std::cout << (result ? "True" : "False") << std::endl;

    return 0;
}
