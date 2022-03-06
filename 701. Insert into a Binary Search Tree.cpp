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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(val < root->val) {
            TreeNode* node = insertIntoBST(root->left, val);
            if(node != nullptr) {
                root->left = node;
            }
        } else if(val > root->val) {
            TreeNode* node = insertIntoBST(root->right, val);
            if(node != nullptr) {
                root->right = node;
            }
        }
        return root;
    }
};