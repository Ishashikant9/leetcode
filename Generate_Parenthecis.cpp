#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        dfs(0, 0, "", n, res);
        return res;        
    }

private:
    void dfs(int openP, int closeP, std::string s, int n, std::vector<std::string>& res) {
        // Base case: if the total number of parentheses equals 2*n (n open, n close)
        if (openP == closeP && openP + closeP == n * 2) {
            res.push_back(s); // Valid parentheses combination found
            return;
        }

        // If we can still add an opening parenthesis, do it
        if (openP < n) {
            dfs(openP + 1, closeP, s + "(", n, res);
        }

        // If we can add a closing parenthesis to balance, do it
        if (closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }
};
