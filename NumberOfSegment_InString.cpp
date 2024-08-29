#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            while (i < n && s[i] == ' ') i++;
            bool flag = false;
            while (i < n && s[i] != ' ') {
                i++;
                flag = true;
            }
            if (flag) count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string s = "Hello, my name is John";
    cout << sol.countSegments(s) << endl;
    return 0;
}
