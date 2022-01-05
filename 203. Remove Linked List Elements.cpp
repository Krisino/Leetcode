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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* headNode = new ListNode(0);
        headNode->next = head;
        ListNode* curNode = headNode;
        while(curNode->next != NULL) {
            if(curNode->next->val == val) {
                ListNode* tmpNode = curNode->next;
                curNode->next = curNode->next->next;
                delete tmpNode;
            }else {
                curNode = curNode->next;
            }
        }
        head = headNode->next;
        delete headNode;
        return head;
    }
};