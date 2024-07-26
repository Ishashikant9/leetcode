#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;        
    }
};

// Function to print in-order traversal of the tree
void printInOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}

int main() {
    // Create the tree: 
    //      4
    //     / \
    //    2   7
    //   / \ / \
    //  1  3 6  9
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    Solution sol;
    cout << "Original tree (in-order): ";
    printInOrder(root);
    cout << endl;
    
    TreeNode* invertedRoot = sol.invertTree(root);
    cout << "Inverted tree (in-order): ";
    printInOrder(invertedRoot);
    cout << endl;
    
    // Clean up allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
