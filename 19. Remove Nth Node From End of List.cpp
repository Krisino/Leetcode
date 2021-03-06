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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *p1 = new_head, *p2 = new_head;
        for(int i = 0;i <= n; i++){
            p2 = p2->next;
        }
        while(p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode * DelNode = p1->next;
        p1->next = DelNode->next;
        delete DelNode;
        return new_head->next;
    }
};
