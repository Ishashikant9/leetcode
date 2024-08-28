#include <iostream>
#include <cstdint> // Include this header for uint32_t

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 31; i >= 0; i--) {
            if(((n >> i) & 1) == 1)
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    uint32_t n = 11; // Example number: 11 in binary is 1011, so the expected output is 3
    int result = sol.hammingWeight(n);
    cout << "The Hamming Weight of " << n << " is: " << result << endl;
    return 0;
}
