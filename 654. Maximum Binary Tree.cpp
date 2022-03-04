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
    TreeNode* traversal(vector<int>& nums, int start, int end) {
        if(start == end) {
            return nullptr;
        }
        if(end - start == 1) {
            return new TreeNode(nums[start]);
        }
        int maxPosition = start;
        for(int i = start + 1; i < end; i++) {
            if(nums[i] > nums[maxPosition]) {
                maxPosition = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxPosition]);
        root->left = traversal(nums, start, maxPosition);
        root->right = traversal(nums, maxPosition + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) {
            return nullptr;
        }
        return traversal(nums, 0, nums.size());
    }
};