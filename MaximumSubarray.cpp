#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,4,-1,7,8}; // Predefined input

    int result = sol.maxSubArray(nums);
    cout << "Maximum subarray sum is: " << result << endl; // Expected output: 23

    return 0;
}
