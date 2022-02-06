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
    // version 1
    // void preOrder(TreeNode* root, vector<int>& res) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     res.push_back(root->val);
    //     preOrder(root->left, res);
    //     preOrder(root->right, res);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     preOrder(root, result);
    //     return result;
    // }

    // version 2
    // vector<int> preorderTraversal(TreeNode* root) {
    //     // 栈用于实现前序遍历
    //     stack<TreeNode*> mp;
    //     // 存放结果
    //     vector<int> result;
    //     if(root == NULL) {
    //         return result;
    //     }
    //     // 先加入根节点
    //     mp.push(root);
    //     while(!mp.empty()) {
    //         // 获取当前根节点
    //         TreeNode* tmp = mp.top();
    //         mp.pop();
    //         // 存入结果数组
    //         result.push_back(tmp->val);
    //         // 前序遍历： 中左右
    //         // 入栈顺序： 中右左
    //         if(tmp->right) {
    //             mp.push(root->right);
    //         }
    //         if(tmp->left) {
    //             mp.push(root->left);
    //         }
    //     }
    //     return result;
    // }

    // version 3
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        // 先加入根节点
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            if(node != NULL) {
                stk.pop();
                if(node->right) {
                    stk.push(node->right);
                }
                if(node->left) {
                    stk.push(node->left);
                }
                stk.push(node);
                stk.push(NULL);
            } else {
                stk.pop();
                node = stk.top();
                stk.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};