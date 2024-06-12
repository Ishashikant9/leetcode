#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0, prev = 0;
        for (char ch : s) {
            switch (ch) {
                case 'I': value += 1; prev = 1; break;
                case 'V': value += (prev == 1) ? 3 : 5; prev = 5; break;
                case 'X': value += (prev == 1) ? 8 : 10; prev = 10; break;
                case 'L': value += (prev == 10) ? 30 : 50; prev = 50; break;
                case 'C': value += (prev == 10) ? 80 : 100; prev = 100; break;
                case 'D': value += (prev == 100) ? 300 : 500; prev = 500; break;
                case 'M': value += (prev == 100) ? 800 : 1000; prev = 1000; break;
            }
        }
        return value;
    }
};

int main() {
    Solution solution;
    string roman;

    cout << "Enter a Roman numeral to convert to an integer: ";
    cin >> roman;

    int result = solution.romanToInt(roman);
    cout << "The integer value of the Roman numeral " << roman << " is " << result << "." << endl;

    return 0;
}