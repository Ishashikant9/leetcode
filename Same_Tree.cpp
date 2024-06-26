#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, the trees are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // If one node is null and the other is not, the trees are not the same
        if (p == nullptr || q == nullptr) {
            return false;
        }
        // If the values of the nodes are different, the trees are not the same
        if (p->val != q->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        if (!isSameTree(p->left, q->left)) {
            return false;
        }
        if (!isSameTree(p->right, q->right)) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    if (solution.isSameTree(tree1, tree2)) {
        std::cout << "The trees are the same." << std::endl;
    } else {
        std::cout << "The trees are not the same." << std::endl;
    }

    // Clean up memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}
