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
    TreeNode* traversal(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, int inorderEnd) {
        if(preorderStart == preorderEnd) {
            return nullptr;
        }
        int rootValue = preorder[preorderStart];
        TreeNode* root = new TreeNode(rootValue);

        if(preorderEnd - preorderStart == 1) {
            return root;
        }

        int midPos;
        for(midPos = inorderStart; midPos < inorderEnd; midPos++) {
            if(inorder[midPos] == rootValue) {
                break;
            }
        }
        
        int leftInorderStart = inorderStart;
        int leftInorderEnd = midPos;

        int rightInorderStart = midPos + 1;
        int rightInorderEnd = inorderEnd;

        int leftPreorderStart = preorderStart + 1;
        int leftPreorderEnd = leftPreorderStart + midPos - inorderStart;
        
        int rightPreorderStart = preorderStart + 1 + midPos - inorderStart;
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(preorder, leftPreorderStart, leftPreorderEnd, inorder, leftInorderStart, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderStart, rightPreorderEnd, inorder, rightInorderStart, rightInorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        }
};