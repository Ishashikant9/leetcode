#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int x = nums.size();
        int y = s.size();

        return x != y;
    }
};

int main() {
    Solution solution;

    // Example usage with one test case
    vector<int> nums = {1, 2, 3, 1};  // Example input

    bool result = solution.containsDuplicate(nums);

    if (result) {
        cout << "The array contains duplicate elements." << endl;
    } else {
        cout << "The array does not contain duplicate elements." << endl;
    }

    return 0;
}
