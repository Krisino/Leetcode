class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr.resize(n + 1);
        arr[0] = 0;
        for(int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return arr[right + 1] - arr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */