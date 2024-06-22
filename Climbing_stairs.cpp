#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the number of steps: ";
    cin >> n;

    int result = solution.climbStairs(n);
    cout << "Number of ways to climb " << n << " steps is: " << result << endl;

    return 0;
}
