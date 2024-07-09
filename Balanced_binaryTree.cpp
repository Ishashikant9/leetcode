#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If the tree is empty, we can say it’s balanced...
        if (root == NULL) return true;
        // Height Function will return -1, when it’s an unbalanced tree...
        if (Height(root) == -1) return false;
        return true;
    }

    // Create a function to return the “height” of a current subtree using recursion...
    int Height(TreeNode* root) {
        // Base case...
        if (root == NULL) return 0;
        // Height of left subtree...
        int leftHeight = Height(root->left);
        // Height of right subtree...
        int rightHeight = Height(root->right);
        // In case of left subtree or right subtree unbalanced or their heights differ by more than ‘1’, return -1...
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;
        // Otherwise, return the height of this subtree as max(leftHeight, rightHeight) + 1...
        return max(leftHeight, rightHeight) + 1;
    }
};

// Function to create a new binary tree node...
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = node->right = NULL;
    return node;
}

int main() {
    Solution solution;

    // Creating a balanced binary tree...
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Check if the tree is balanced...
    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    // Creating an unbalanced binary tree...
    //         1
    //        /
    //       2
    //      /
    //     3
    TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->left->left = newNode(3);

    // Check if the tree is balanced...
    if (solution.isBalanced(root2)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
