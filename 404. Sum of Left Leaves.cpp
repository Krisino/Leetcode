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
    // Version one
    // int sumOfLeftLeaves(TreeNode* root) {
    //     int result = 0;
    //     stack<TreeNode*> stk;
    //     if(root == nullptr) {
    //         return 0;
    //     }
    //     stk.push(root);
    //     while(!stk.empty()) {
    //         TreeNode* node = stk.top();
    //         stk.pop();
    //         // 右结点若不为空，则一定要加入栈
    //         if(node->right != nullptr) {
    //             stk.push(node->right);
    //         }
    //         // 左节点为叶子结点，计算和
    //         if(node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
    //             result += node->left->val;
    //         // 左节点不是叶子结点，加入栈进行下一步判断
    //         } else if(node->left != nullptr) {
    //             stk.push(node->left);
    //         }
    //     }
    //     return result;
    // }
    // version two
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue =  sumOfLeftLeaves(root->right);
        int midValue = 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            midValue = root->left->val;
        }
        return leftValue + midValue + rightValue;
    }
};