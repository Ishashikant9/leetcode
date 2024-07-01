#include <iostream>
#include <unordered_set>

class Solution {
private:
    int nextNumber(int n) {
        int newNumber = 0;
        while (n != 0) {
            int num = n % 10;
            newNumber += num * num;
            n = n / 10;
        }
        return newNumber;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> set;
        while (n != 1 && !set.count(n)) {
            set.insert(n);
            n = nextNumber(n);
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    int n;

    std::cout << "Enter a number to check if it is happy: ";
    std::cin >> n;

    if (solution.isHappy(n)) {
        std::cout << n << " is a happy number." << std::endl;
    } else {
        std::cout << n << " is not a happy number." << std::endl;
    }

    return 0;
}
