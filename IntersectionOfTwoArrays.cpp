#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> answer;
        for (int num : nums2) {
            if (s.count(num)) {
                answer.insert(num);
            }
        }
        return vector<int>(answer.begin(), answer.end());
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
    vector<int> nums1_1 = {1, 2, 2, 1};
    vector<int> nums2_1 = {2, 2}; // Expected output: [2]
    cout << "Intersection: ";
    printVector(sol.intersection(nums1_1, nums2_1));

    // Test case 2
    vector<int> nums1_2 = {4, 9, 5};
    vector<int> nums2_2 = {9, 4, 9, 8, 4}; // Expected output: [9, 4]
    cout << "Intersection: ";
    printVector(sol.intersection(nums1_2, nums2_2));

    // Test case 3
    vector<int> nums1_3 = {1, 2, 3};
    vector<int> nums2_3 = {4, 5, 6}; // Expected output: []
    cout << "Intersection: ";
    printVector(sol.intersection(nums1_3, nums2_3));

    return 0;
}
