#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n >= 3) {
            if(n % 3 != 0) return false;
            n = n / 3;
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (solution.isPowerOfThree(number)) {
        cout << number << " is a power of three." << endl;
    } else {
        cout << number << " is not a power of three." << endl;
    }

    return 0;
}
