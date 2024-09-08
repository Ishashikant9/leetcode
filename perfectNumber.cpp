#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) 
    {
        if (num == 1) return false;
        
        vector<int> all_divisor;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                all_divisor.push_back(i);
                if (num / i != i)
                    all_divisor.push_back(num / i);
            }
        }

        int sum = 1;
        for (int val : all_divisor)
            sum += val;

        return sum == num;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (sol.checkPerfectNumber(num))
        cout << num << " is a perfect number.\n";
    else
        cout << num << " is not a perfect number.\n";
    
    return 0;
}
