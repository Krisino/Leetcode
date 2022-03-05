/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int result = Integer.MAX_VALUE;
    TreeNode pre = null;

    void traversal(TreeNode root) {
        if(root == null) {
            return;
        }
        traversal(root.left);
        if(pre != null && root.val - pre.val < result) {
            result = root.val - pre.val;
        }
        pre = root;
        traversal(root.right);
    }

    public int getMinimumDifference(TreeNode root) {
        traversal(root);
        return result;
    }
}