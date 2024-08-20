#include <iostream>
#include <vector>
#include <cmath> // Required for abs()

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int mark = abs(nums[i]) - 1;
            if (nums[mark] > 0) {
                nums[mark] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    vector<int> result = sol.findDisappearedNumbers(nums);
    
    // Output the result
    cout << "Disappeared numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
