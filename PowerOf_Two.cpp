#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter a number to check if it's a power of two: ";
    cin >> n;
    
    if (solution.isPowerOfTwo(n)) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }

    return 0;
}

