#include <iostream>
#include <vector>
#include <climits> // Required for LLONG_MIN

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] == max1 || nums[i] == max2 || nums[i] == max3) continue;

            if (nums[i] > max1) {
                max3 = max(max3, max2);
                max2 = max(max2, max1);
                max1 = nums[i];
            }
            else if (nums[i] > max2) {
                max3 = max(max3, max2);
                max2 = nums[i];
            }
            else if (nums[i] > max3) {
                max3 = nums[i];
            }
        }

        // If max3 has been updated from its initial value, return it
        if (max3 != LLONG_MIN) return max3;

        // Otherwise, return the maximum value
        return max1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 1};

    int result = sol.thirdMax(nums);

    // Output the result
    cout << "The third maximum number is: " << result << endl;

    return 0;
}
