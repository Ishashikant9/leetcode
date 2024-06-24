#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int n = (int)nums.size();
        int a = 0;
        for(int i = 0; i < n; i++) {
            a = a ^ nums[i];
        }
        return a;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    
    // Sample input
    std::vector<int> nums = {4, 1, 2, 1, 2};
    
    // Find the single number
    int result = solution.singleNumber(nums);
    
    // Print the result
    std::cout << "The single number is: " << result << std::endl;
}