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
    // void function(TreeNode* root, vector<int> &ans){
    //     if(root == nullptr) return;
    //     function(root->left, ans);
    //     ans.push_back(root->val);
    //     function(root->right, ans);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     function(root, ans);
    //     return ans;
    // }
    // Version 2
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while(root != nullptr || stk.size() > 0){
            if(root != nullptr){
                stk.push(root);
                root = root->left;
            } else {
                TreeNode* tmp = stk.top();
                stk.pop();
                ans.push_back(tmp->val);
                root = tmp->right;
            }
        }
        return ans;
    }
};