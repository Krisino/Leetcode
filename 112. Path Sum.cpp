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
    bool result;
    void backtrack(TreeNode* root, int sum, int target) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr && sum + root->val == target) {
            result = true;
            return;
        }
        if(root->left) {
            backtrack(root->left, sum + root->val, target);
        }
        if(root->right) {
            backtrack(root->right, sum + root->val, target);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        result = false;
        backtrack(root, 0, targetSum);
        return result;
    }
};