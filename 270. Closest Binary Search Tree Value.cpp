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
    double closetDiff;
    int closetAns;

    void dfs(TreeNode* root, const double& target) {
        if(root == nullptr) {
            return;
        }
        dfs(root->left, target);
        if(fabs(root->val - target) < closetDiff) {
            closetDiff = abs(root->val - target);
            closetAns = root->val;
        }
        dfs(root->right, target);
    }

    int closestValue(TreeNode* root, double target) {
        closetDiff = DBL_MAX;
        dfs(root, target);
        return closetAns;
    }
};