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
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftHeight = 0;
        int rightHeight = 0;
        while(left) {
            left = left->left;
            leftHeight++;
        }
        while(right) {
            right = right->right;
            rightHeight++;
        }
        if(leftHeight == rightHeight) {
            return (2 << leftHeight) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};