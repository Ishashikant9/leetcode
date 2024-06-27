#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> v(i + 1, 1);
            for (int j = 1; j < i; j++) {
                v[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int numRows = 5;  // Example: Generating 5 rows of Pascal's Triangle
    vector<vector<int>> result = solution.generate(numRows);

    // Printing the result
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
