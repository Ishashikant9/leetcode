#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequencyMap;

        // Count the frequency of each number in the array
        for (int num : arr)
            frequencyMap[num]++;

        unordered_set<int> uniqueFrequencies;

        // Check if all frequencies are unique
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
            if (!uniqueFrequencies.insert(it->second).second)
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    if (sol.uniqueOccurrences(arr)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
