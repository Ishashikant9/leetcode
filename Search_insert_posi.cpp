#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2; // to avoid potential overflow

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        // If element is not present, return the position where it should be inserted
        return start;
    }
};

int main() 
{
    Solution solution;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = solution.searchInsert(nums, target);
    std::cout << "The target " << target << " is at index " << result << std::endl;

    target = 2;
    result = solution.searchInsert(nums, target);
    std::cout << "The target " << target << " should be inserted at index " << result << std::endl;

    target = 7;
    result = solution.searchInsert(nums, target);
    std::cout << "The target " << target << " should be inserted at index " << result << std::endl;

    target = 0;
    result = solution.searchInsert(nums, target);
    std::cout << "The target " << target << " should be inserted at index " << result << std::endl;

    return 0;
}