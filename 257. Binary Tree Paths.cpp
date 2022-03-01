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
    vector<string> result;
    vector<int> path;

    void backtrack(TreeNode* root) {
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            string onePath = "";
            for(int i = 0; i < path.size() - 1; i++) {
                onePath += to_string(path[i]) + "->";
            }
            onePath += to_string(path[path.size() - 1]);
            result.push_back(onePath);
            return;
        }
        if(root->left) {
            backtrack(root->left);
            path.pop_back();
        }
        if(root->right) {
            backtrack(root->right);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        result.clear();
        path.clear();
        backtrack(root);
        return result;
    }
};