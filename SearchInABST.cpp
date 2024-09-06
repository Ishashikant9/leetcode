#include <iostream>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        } else if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

// Helper function to create a new node
TreeNode* newNode(int item) {
    TreeNode* temp = new TreeNode(item);
    return temp;
}

// Insert a new node with given key in the BST
TreeNode* insert(TreeNode* node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node;
}

int main() {
    Solution sol;

    TreeNode* root = nullptr;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    int target = 2;
    TreeNode* result = sol.searchBST(root, target);
    if (result != nullptr)
        cout << "Node found with value: " << result->val << endl;
    else
        cout << "Node with value " << target << " not found." << endl;

    return 0;
}
