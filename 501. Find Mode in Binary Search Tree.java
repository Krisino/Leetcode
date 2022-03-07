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
    private int count;
    private int maxCount;
    private TreeNode pre;
    private ArrayList<Integer> resultList;

    void searchBST(TreeNode root) {
        if(root == null) {
            return;
        }
        searchBST(root.left);

        if(pre == null) {
            count = 1;
        } else if(pre.val == root.val) {
            count++;
        } else {
            count = 1;
        }

        pre = root;
        
        if(count == maxCount) {
            resultList.add(root.val);
        } else if(count > maxCount) {
            maxCount = count;
            resultList.clear();
            resultList.add(root.val);
        }
        
        searchBST(root.right);
    }

    public int[] findMode(TreeNode root) {
        count = 0;
        maxCount = 0;
        pre = null;
        resultList = new ArrayList<>();
        searchBST(root);
        int[] result = new int[resultList.size()];
        for(int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}