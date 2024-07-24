#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        
        return n == 1;
    }
};

int main() {
    Solution sol;

    // Test cases
    int test1 = 6; // Expected output: True
    int test2 = 8; // Expected output: True
    int test3 = 14; // Expected output: False
    int test4 = 1; // Expected output: True

    cout << (sol.isUgly(test1) ? "True" : "False") << endl;
    cout << (sol.isUgly(test2) ? "True" : "False") << endl;
    cout << (sol.isUgly(test3) ? "True" : "False") << endl;
    cout << (sol.isUgly(test4) ? "True" : "False") << endl;

    return 0;
}
