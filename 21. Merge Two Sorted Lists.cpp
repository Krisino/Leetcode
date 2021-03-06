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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 != nullptr && l2 != nullptr){
            if(l2->val < l1->val) {
                cur->next =l2;
                cur = cur->next;
                l2 = l2->next;
            }else {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
        }
        if(l1 == nullptr) {
            cur->next = l2;
        } else if (l2 == nullptr) {
            cur->next = l1;
        }
        return head->next;
    }
};