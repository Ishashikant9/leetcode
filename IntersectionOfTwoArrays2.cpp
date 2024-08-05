#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        vector<int> result;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return result;
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
    vector<int> nums2_1 = {2, 2}; // Expected output: [2, 2]
    cout << "Intersection: ";
    printVector(sol.intersect(nums1_1, nums2_1));

    // Test case 2
    vector<int> nums1_2 = {4, 9, 5};
    vector<int> nums2_2 = {9, 4, 9, 8, 4}; // Expected output: [4, 9]
    cout << "Intersection: ";
    printVector(sol.intersect(nums1_2, nums2_2));

    // Test case 3
    vector<int> nums1_3 = {1, 2, 3};
    vector<int> nums2_3 = {4, 5, 6}; // Expected output: []
    cout << "Intersection: ";
    printVector(sol.intersect(nums1_3, nums2_3));

    return 0;
}
