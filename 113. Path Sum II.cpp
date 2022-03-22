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
    vector<vector<int> > ans;

    void dfs(TreeNode* root, vector<int> path,int sum, int target) {
        if(root == nullptr) {
            return;
        }
        if(sum == target && root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }
        if(root->left) {
            path.push_back(root->left->val);
            dfs(root->left, path, sum + root->left->val, target);
            path.pop_back();
        }
        if(root->right) {
            path.push_back(root->right->val);
            dfs(root->right, path, sum + root->right->val, target);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        if(root == nullptr) {
            return ans;
        }
        vector<int> path;
        path.push_back(root->val);
        dfs(root, path, root->val, targetSum);
        return ans;
    }
};