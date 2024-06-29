#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
           if (n <= 3) {
               return n;
           }

           int a = 3;
           int b = 2;

           for (int i = 0; i < n - 3; i++) {
               a = a + b;
               b = a - b;
           }
           return a;
    }
};

int main() {
    Solution solution;
    int n;

    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    int result = solution.climbStairs(n);
    std::cout << "Number of ways to climb " << n << " steps is: " << result << std::endl;

    return 0;
}
