#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {0, 1, 0, 3, 12}; // Expected output: [1, 3, 12, 0, 0]
    cout << "Original: ";
    printVector(nums1);
    sol.moveZeroes(nums1);
    cout << "After moveZeroes: ";
    printVector(nums1);

  

    return 0;
}
