#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& arr, vector<int>& temp, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0) {
            return;
        }

        if (i == arr.size()) {
            return;
        }

        solve(i + 1, arr, temp, target); // Exclude the current element
        temp.push_back(arr[i]); // Include the current element
        solve(i, arr, temp, target - arr[i]); // Keep the current element for the next call
        temp.pop_back(); // Backtrack to remove the current element
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        ans.clear();
        vector<int> temp;
        solve(0, arr, temp, target);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(arr, target);

    cout << "Combinations that sum to " << target << " are:\n";
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
