#include <iostream>
#include <vector>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to find the number of good special subsets (palindromic) and count all subsets
long long countGoodSpecialSubsetsAndAllSubsets(const string& s) {
    int n = s.size();
    long long count = 0;  // To count palindromic subsets
    long long count1 = 0; // To count all subsets
    vector<string> allSubsets;

    // Generate all possible subsets of indices using bitmasking
    for (int mask = 1; mask < (1 << n); mask++) {
        string subset;

        // Generate the subset corresponding to the current mask
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset += s[i];
            }
        }

        // Print all subsets (this is what you want to display)
        allSubsets.push_back(subset);

        // Increment count1 for every subset (including palindromic and non-palindromic)
        count1++;

        // Check if the generated subset forms a palindrome
        if (isPalindrome(subset)) {
            count = (count + 1) % MOD;
        }
    }

    // Print all subsets
    cout << "All subsets: ";
    for (const string& subset : allSubsets) {
        cout << "\"" << subset << "\" ";
    }
    cout << endl;

    // Return the total number of palindromic subsets
    return count1; // Return the count of all subsets
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    // Calculate and print the result
    long long result = countGoodSpecialSubsetsAndAllSubsets(s);
    cout << "Total number of subsets: " << result << endl;

    return 0;
}
