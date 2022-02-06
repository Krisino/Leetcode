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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     TreeNode* cur = root;
    //     stack<TreeNode*> mp;
    //     while(cur != NULL || !mp.empty()) {
    //         if(cur != NULL) {
    //             mp.push(cur);
    //             cur = cur->left;
    //         } else {
    //             cur = mp.top();
    //             mp.pop();
    //             ans.push_back(cur->val);
    //             cur = cur->right;
    //         }
    //     }
    //     return ans;
    // }

    // Version 3
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if(root == NULL) {
            return result;
        }
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            if(node != NULL) {
                stk.pop();
                if(node->right) {
                    stk.push(node->right);
                }
                stk.push(node);
                stk.push(NULL);
                if(node->left) {
                    stk.push(node->left);
                }
            }else {
                stk.pop();
                node = stk.top();
                stk.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};