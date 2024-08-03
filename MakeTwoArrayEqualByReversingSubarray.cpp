#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt1(1001);
        vector<int> cnt2(1001);
        for (int& v : target) {
            ++cnt1[v];
        }
        for (int& v : arr) {
            ++cnt2[v];
        }
        return cnt1 == cnt2;
    }
};

void printResult(bool result) {
    cout << (result ? "True" : "False") << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> target1 = {1, 2, 3, 4};
    vector<int> arr1 = {2, 4, 1, 3}; // Expected output: true
    printResult(sol.canBeEqual(target1, arr1));

    // Test case 2
    vector<int> target2 = {7};
    vector<int> arr2 = {7}; // Expected output: true
    printResult(sol.canBeEqual(target2, arr2));

    return 0;
}
