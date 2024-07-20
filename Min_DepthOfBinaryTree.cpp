#include <iostream>
#include <algorithm> // for std::min

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        return 1 + std::min(minDepth(root->right), minDepth(root->left));
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    std::cout << "Minimum Depth of the Binary Tree: " << sol.minDepth(root) << std::endl;

    // Deleting allocated nodes to avoid memory leak
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
