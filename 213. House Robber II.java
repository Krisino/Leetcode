class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if(len == 1) {
            return nums[0];
        };
        
        int result = 0;
        int pre, cur, temp;
        pre = 0;
        cur = 0;
        for(int i = 0; i < len - 1; i++) {
            temp = cur;
            cur = Math.max(pre + nums[i], cur);
            pre = temp;
        }
        result = Math.max(result, cur);        
        pre = 0;
        cur = 0;
        for(int i = 1; i < len; i++) {
            temp = cur;
            cur = Math.max(pre + nums[i], cur);
            pre = temp;
        }
        return Math.max(result, cur);
    }
}