#include <iostream>
#include <string>
using namespace std;

// Function to check if a number has only contiguous 1s in binary
bool isSterileNeutrino(int num) {
    string binary = "";
    while (num > 0) {
        binary = char((num % 2) + '0') + binary; // Convert to binary
        num /= 2;
    }
    // Check if the binary representation contains only contiguous '1's
    for (char c : binary) {
        if (c != '1') return false;
    }
    return true;
}

// Function to find the smallest valid Sterile Neutrino >= p
int findSterileNeutrino(int p) {
    while (!isSterileNeutrino(p)) {
        p++;
    }
    return p;
}

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int p;
        cin >> p;
        cout << findSterileNeutrino(p) << endl;
    }
    return 0;
}
