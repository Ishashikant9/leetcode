#include <iostream>
#include <vector>
#include <algorithm> // for sort and next_permutation
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        do {
            v.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return v;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 2};  // Predefined input for testing

    vector<vector<int>> result = sol.permuteUnique(nums);

    // Output the result
    cout << "Unique permutations of the array:\n";
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
