/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result = INT_MAX;
    TreeNode* pre = nullptr;

    void traversal(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        traversal(root->left);
        if(pre != nullptr && root->val - pre->val < result) {
            result = root->val - pre->val;
        }
        pre = root;
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};