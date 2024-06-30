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
    bool match(TreeNode* root1, TreeNode* root2){
        if(root1 != NULL && root2 != NULL){
            bool a = match(root1->left , root2->right);
            bool b = match(root1->right , root2->left);

            if(root1->val == root2->val && a && b){
                return true;
            } else {
                return false;
            }
        } else if (root1 == NULL && root2 == NULL) {
            return true;
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;

        return match(root->left, root->right);
    }
};

int main() {
    // Creating a symmetric tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    if(sol.isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    // Cleaning up the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
