#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Handle the empty array case
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    int newLength = solution.removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}