#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string nums1, string nums2) {
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        int sum = 0, carry = 0;
        string ans;
        
        // Add digits from both strings
        while (i >= 0 && j >= 0) {
            sum = (nums1[i] - '0') + (nums2[j] - '0') + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
            i--;
            j--;
        }
        
        // Add remaining digits from nums1
        while (i >= 0) {
            sum = nums1[i] - '0' + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
            i--;
        }
        
        // Add remaining digits from nums2
        while (j >= 0) {
            sum = nums2[j] - '0' + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
            j--;
        }
        
        // If there's still a carry left
        if (carry > 0) {
            ans.push_back(carry + '0');
        }
        
        // Reverse the result to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Input two numbers as strings
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Get the result by calling addStrings
    string result = sol.addStrings(num1, num2);

    // Output the result
    cout << "Sum: " << result << endl;

    return 0;
}

