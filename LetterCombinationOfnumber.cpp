#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    string path, digit;
    vector<string> ans, store = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtrack(int cur) {
        if (path.size() == n) {
            ans.push_back(path);
            return;
        }
        string s = store[digit[cur] - '0'];
        for (char ch : s) {
            path.push_back(ch);
            backtrack(cur + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        digit = digits;
        n = digit.size();
        backtrack(0);
        return ans;
    }
};

int main() {
    Solution sol;
    string digits;

    // Example test cases
    vector<string> testCases = {"23", "2", ""};

    for (const auto& digits : testCases) {
        vector<string> result = sol.letterCombinations(digits);
        cout << "Input: \"" << digits << "\" -> Output: ";
        for (const auto& combination : result) {
            cout << "\"" << combination << "\" ";
        }
        cout << endl;
    }

    return 0;
}

