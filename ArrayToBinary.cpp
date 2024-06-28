#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* solve(vector<int>& nums, int low, int high) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = solve(nums, low, mid - 1);
            root->right = solve(nums, mid + 1, high);
            return root;
        }
        return nullptr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};

void printInOrder(TreeNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    vector<int> nums = {1, 3, 4, 5, 9};
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "In-order traversal of the constructed BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
