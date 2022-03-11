class Solution {
    public boolean canJump(int[] nums) {
        int maxStep = 0;
        int i;
        for(i = 0; i <= maxStep; i++) {
            if(maxStep < i + nums[i]) {
                maxStep = i + nums[i];
            }
            if(maxStep >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}