/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        if(root == nullptr) {
            return res;
        }
        queue<Node*> que;
        que.push(root);
        while(!que.empty()) {
            int n = que.size();
            vector<int> arr(n);
            for(int i = 0; i < n; i++) {
                Node* node = que.front();
                que.pop();
                arr[i] = node->val;
                for(int j = 0; j < node->children.size(); j++) {
                    if(node->children[j] != nullptr) {
                        que.push(node->children[j]);
                    }
                }
            }
            res.push_back(arr);
        }
        return res;
    }
};