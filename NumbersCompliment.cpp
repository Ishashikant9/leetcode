#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        
        unsigned int mask = ~0;
        
        while (num & mask) {
            mask <<= 1;
        }
        
        return ~mask & ~num;
    }
};

int main() {
    Solution sol;
    int num = 5;
    
    int result = sol.findComplement(num);
    
    cout << "The complement of " << num << " is: " << result << endl;
    
    return 0;
}
