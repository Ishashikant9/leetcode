#include <iostream>
#include <queue> // For level order traversal

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* solve(TreeNode* node, int val) {
        if (node == NULL) {
            node = new TreeNode(val);
            return node;
        }
        
        if (val < node->val) {
            node->left = solve(node->left, val);
        } else if (val > node->val) {
            node->right = solve(node->right, val);
        }
        
        return node;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root, val);
    }
};

// Utility function to perform level order traversal of a binary tree
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        cout << node->val << " ";
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    // Example usage of the Solution class
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Initialize the root of the BST (example: inserting values 4, 2, 7, 1, 3)
    TreeNode* root = NULL;
    root = sol.insertIntoBST(root, 4);
    sol.insertIntoBST(root, 2);
    sol.insertIntoBST(root, 7);
    sol.insertIntoBST(root, 1);
    sol.insertIntoBST(root, 3);
    
    // Perform level order traversal to print the BST
    cout << "Level order traversal of the BST:" << endl;
    levelOrderTraversal(root);
    cout << endl;
    
    return 0;
}
