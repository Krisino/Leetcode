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
    // Version 1
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root == NULL) {
    //         return root;
    //     }
    //     swap(root->left, root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     return root;
    // }

    // Version 2
        TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            swap(node->left, node->right);
            stk.pop();
            if(node->left) {
                stk.push(node->left);
            }
            if(node->right) {
                stk.push(node->right);
            }
        }
        return root;
    }
};