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
    // vector<int> arr;

    // void traversal(TreeNode* root) {
    //     if(root == nullptr) {
    //         return;
    //     }
    //     traversal(root->left);
    //     arr.push_back(root->val);
    //     traversal(root->right);
    // }

    // bool isValidBST(TreeNode* root) {
    //     traversal(root);
    //     for(int i = 1; i < arr.size(); i++) {
    //         if(arr[i] <= arr[i - 1]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // Version 2
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        bool left = isValidBST(root->left);
        if(pre != nullptr && root->val <= pre->val) {
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};