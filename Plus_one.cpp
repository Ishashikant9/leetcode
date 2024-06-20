#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1)
                v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};

int main() {
    // Initialize a vector
    vector<int> digits = {1, 2, 9};

    // Create an instance of Solution
    Solution sol;
    
    // Call the plusOne function
    vector<int> result = sol.plusOne(digits);
    
    // Print the result
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}