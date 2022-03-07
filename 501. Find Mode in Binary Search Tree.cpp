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
    int count;
    int maxCount;
    TreeNode* pre;
    vector<int> result;

    void searchBST(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        searchBST(root->left);
        if(pre == nullptr) {
            count = 1;
        } else if(root->val == pre->val) {
            count++;
        } else {
            count = 1;
        }
        pre = root;
        if(count == maxCount) {
            result.push_back(root->val);
        } else if(count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(root->val);
        }
        searchBST(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = nullptr;
        result.clear();

        searchBST(root);
        return result;
    }
};