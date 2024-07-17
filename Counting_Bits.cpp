#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        // iterating from 0 to n
        for(int i = 0; i <= n; i++) {
            // sum is initialized as 0
            int sum = 0;
            int num = i;
            // while num not equals zero
            while(num != 0) {
                // we have to count 1's in binary representation of i, therefore % 2
                sum += num % 2;
                num = num / 2;
            }
            // add sum to ans vector
            ans.push_back(sum);
        }
        // return 
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = solution.countBits(n);

    cout << "Number of 1's in binary representation for numbers from 0 to " << n << " are:" << endl;
    for(int i = 0; i <= n; i++) {
        cout << i << ": " << result[i] << endl;
    }

    return 0;
}
