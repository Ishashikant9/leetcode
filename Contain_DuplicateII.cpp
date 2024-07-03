#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                if (abs(i - mp[nums[i]]) <= k) {
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test case
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;
    
    bool result = solution.containsNearbyDuplicate(nums, k);
    
    if (result) {
        cout << "True" << endl;  // There are nearby duplicates within distance k
    } else {
        cout << "False" << endl;  // There are no nearby duplicates within distance k
    }
    
    return 0;
}
