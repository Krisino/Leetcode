/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }
        int len = 1;
        ListNode* tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        while(k >= len) {
            k%= len;
        }
        int num = len - k - 1;
        ListNode* cur = head;
        while(num--){
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};