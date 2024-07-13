#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {3, 0, 1}; // Example vector
    Solution sol;
    int missing = sol.missingNumber(nums);
    cout << "Missing number: " << missing << endl;
    return 0;
}
