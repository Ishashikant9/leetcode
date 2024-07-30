#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1;
        int e = num;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (num % mid == 0 && mid == num / mid) return true;
            if (mid > num / mid) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test cases
    int test1 = 16; // Expected output: true
    int test2 = 14; // Expected output: false
    int test3 = 1; // Expected output: true
    int test4 = 25; // Expected output: true
    int test5 = 26; // Expected output: false

    cout << (sol.isPerfectSquare(test1) ? "True" : "False") << endl;
    cout << (sol.isPerfectSquare(test2) ? "True" : "False") << endl;
    cout << (sol.isPerfectSquare(test3) ? "True" : "False") << endl;
    cout << (sol.isPerfectSquare(test4) ? "True" : "False") << endl;
    cout << (sol.isPerfectSquare(test5) ? "True" : "False") << endl;

    return 0;
}
