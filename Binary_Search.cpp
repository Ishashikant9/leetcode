#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bs(vector<int>& nums, int low, int high, int target) {
        if(low > high) return -1;
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) {
            return bs(nums, low, mid - 1, target);
        }
        return bs(nums, mid + 1, high, target);
    }

    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = sol.search(nums, target);
    if(result != -1)
        cout << "Target " << target << " found at index: " << result << endl;
    else
        cout << "Target " << target << " not found." << endl;
    return 0;
}
