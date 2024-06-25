#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    int result = sol.majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}
