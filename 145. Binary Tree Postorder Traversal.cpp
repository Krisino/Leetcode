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
    // verison one
    // void preOrder(TreeNode* root, vector<int>& res) {
    // if(root == NULL) {
    //     return;
    // }
    // preOrder(root->left, res);
    // preOrder(root->right, res);
    // res.push_back(root->val);
    // }
    
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     preOrder(root, result);
    //     return result;
    // }

    // version two
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if(root == NULL) {
            return result;
        }
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            result.push_back(node->val);
            stk.pop();
            if(node->left) {
                stk.push(node->left);
            }
            if(node->right) {
                stk.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};