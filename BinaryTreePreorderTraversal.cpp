#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> ans;

    void preOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        ans.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();
        preOrder(root);
        return ans;
    }
};

int main() {
    Solution sol;

    // Creating a binary tree directly in the main function
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Perform preorder traversal
    vector<int> result = sol.preorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
