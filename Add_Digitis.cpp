#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum;
        while(num / 10 != 0) {
            sum = 0;
            while(num) {
                sum += num % 10;
                num = num / 10;
            }
            num = sum;
        }
        return num;
    }
};

int main() {
    Solution solution;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = solution.addDigits(num);
    cout << "The result is: " << result << endl;

    return 0;
}
