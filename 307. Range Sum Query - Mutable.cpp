class NumArray {
public:
    vector<int> arr, tree;
    int size;

    void build_tree(int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
        } else {
            int mid = start + (end - start) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            build_tree(left_node, start, mid);
            build_tree(right_node, mid + 1, end);
            tree[node] = tree[left_node] + tree[right_node];
        }
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if(start == end) {
            arr[idx] = val;
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            if(idx >= start && idx <= mid) {
                update_tree(left_node, start, mid, idx, val);
            } else {
                update_tree(right_node, mid + 1, end, idx, val);
            }
            tree[node] = tree[left_node] + tree[right_node];
        }
    }

    int query_tree(int node, int start, int end, int L, int R) {
        if(start > R || end < L) {
            return 0;
        } else if(start >= L && end <= R) {
            return tree[node];
        } else {
            int mid = start + (end - start) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int left_sum = query_tree(left_node, start, mid, L, R);
            int right_sum = query_tree(right_node, mid + 1, end, L, R);
            return left_sum + right_sum;
        }
    }

    NumArray(vector<int>& nums) {
        size = nums.size();
        if(size == 0) {
            return;
        }
        arr = nums;
        tree.resize(4 * size);
        build_tree(0, 0, size - 1);
    }
    
    void update(int index, int val) {
        update_tree(0, 0, size - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query_tree(0, 0, size - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */