#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        // Iterate through powers of 4 from 4^0 to 4^15
        for (int i = 0; i <= 15; i++) {
            int powerOfFour = pow(4, i);
            
            // If we find a power of four equal to 'n', return true
            if (powerOfFour == n)
                return true;
            
            // If the current power of four is greater than 'n', there's no need to continue
            if (powerOfFour > n)
                return false;
        }
        
        // 'n' is not a power of four
        return false;
    }
};

int main() {
    Solution sol;

    // Test cases
    int test1 = 16; // Expected output: True (4^2)
    int test2 = 5; // Expected output: False
    int test3 = 1; // Expected output: True (4^0)
    int test4 = 64; // Expected output: True (4^3)

    cout << (sol.isPowerOfFour(test1) ? "True" : "False") << endl;
    cout << (sol.isPowerOfFour(test2) ? "True" : "False") << endl;
    cout << (sol.isPowerOfFour(test3) ? "True" : "False") << endl;
    cout << (sol.isPowerOfFour(test4) ? "True" : "False") << endl;

    return 0;
}
