#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};

// Main method to run the code in VS Code
int main() {
    // Define sample input
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Call the maxProfit method and store the result
    int result = sol.maxProfit(prices);
    
    // Print the result
    std::cout << "Maximum profit: " << result << std::endl;
    
    return 0;
}
