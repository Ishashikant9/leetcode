#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> count = {{0, 0}, {1, 0}, {2, 0}};

        // Count the occurrences of 0, 1, and 2
        for (int num : nums) {
            count[num]++;
        }

        // Rearrange the array based on the counts
        int idx = 0;
        for (int color = 0; color < 3; color++) {
            int freq = count[color];
            for (int j = 0; j < freq; j++) {
                nums[idx] = color;
                idx++;
            }
        }        
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution solution;
    solution.sortColors(nums);

    // Print the sorted array
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
