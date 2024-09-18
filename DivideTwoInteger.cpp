#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the case where dividend is equal to divisor
        if (dividend == divisor) return 1;

        unsigned int ans = 0;
        int sign = 1;

        // Determine the sign of the result
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;

        // Convert both dividend and divisor to positive integers
        unsigned int n = abs(dividend), d = abs(divisor);

        // Perform the division
        while (n >= d) {
            int count = 0;
            while (n > (d << (count + 1)))
                count++;
            n -= d << count;
            ans += 1 << count;
        }

        // Handle overflow case
        if (ans == (1 << 31) && sign == 1) return INT_MAX;

        return sign * ans;
    }
};

int main() {
    Solution sol;

    int dividend = 10; // Example predefined input
    int divisor = 3;

    int result = sol.divide(dividend, divisor);
    cout << "Result of dividing " << dividend << " by " << divisor << " is: " << result << endl;

    return 0;
}
