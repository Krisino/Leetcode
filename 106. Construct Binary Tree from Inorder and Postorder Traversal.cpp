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
    // [Start, End) 左闭右开区间
    TreeNode* traversal(vector<int>& inorder, int inorderSatrt, int inorderEnd, vector<int>& postorder, int postorderStart, int postorderEnd) {
        // 空结点直接返回nullptr
        if(postorderStart == postorderEnd) {
            return nullptr;
        }
        // 取后序最后一个结点作为根节点
        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue);
        // 若只有一个结点，返回根节点
        if(postorderEnd - postorderStart == 1) {
            return root;
        }
        // 在中序里找到rootValue的位置
        int midPos;
        for(midPos = inorderSatrt; midPos < inorderEnd; midPos++) {
            if(inorder[midPos] == rootValue) {
                break;
            }
        }
        // 中序rootValue左侧区间
        int leftInorderStart = inorderSatrt;
        int leftInorderEnd = midPos;
        // 中序rootValue右侧区间
        int rightInorderStart = midPos + 1;
        int rightInorderEnd = inorderEnd;
        // 后序rootValue左侧区间
        int leftPostorderStart = postorderStart;
        int leftPostorderEnd = postorderStart + midPos - inorderSatrt;
        // 后序rootValue右侧区间
        int rightPostorderStart = postorderStart + midPos - inorderSatrt;
        int rightPostorderEnd = postorderEnd - 1;
        // 递归部分
        root->left = traversal(inorder, leftInorderStart, leftInorderEnd, postorder, leftPostorderStart, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderStart, rightInorderEnd, postorder, rightPostorderStart, rightPostorderEnd);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};