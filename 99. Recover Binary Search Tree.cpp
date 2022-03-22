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
    TreeNode* changeNode1;
    TreeNode* changeNode2;
    TreeNode* pre;
    
    void dfs(TreeNode* cur) {
        if(cur == nullptr) {
            return;
        }
        dfs(cur->left);

        if(pre == nullptr) {
            pre = cur;
        }
        if(pre->val > cur->val) {
            changeNode2 = cur;
            if(changeNode1 == nullptr) {
                changeNode1 = pre;
            }
        }

        pre = cur;

        dfs(cur->right);
    }

    void recoverTree(TreeNode* root) {
        changeNode1 = nullptr;
        changeNode2 = nullptr;
        pre = nullptr;
        dfs(root);
        int temp = changeNode1->val;
        changeNode1->val = changeNode2->val;
        changeNode2->val = temp;
    }
};