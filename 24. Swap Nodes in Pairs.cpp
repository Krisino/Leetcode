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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* headNode = new ListNode(0);
        headNode->next = head;
        ListNode* curNode = headNode;
        while(curNode->next != nullptr && curNode->next->next != nullptr) {
            // 由于 next 重新指向后，链表会断开，故需要保存这些要用到的ListNode
            ListNode* tempNode1 = curNode->next;
            ListNode* tempNode2 = curNode->next->next->next;

            // 顺序不能交换
            curNode->next = tempNode1->next;
            curNode->next->next = tempNode1;
            tempNode1->next = tempNode2;

            // 进行下一组两两交换
            curNode = curNode->next->next;
        }
        ListNode* ans = headNode->next;
        // 释放 headNode 内存占用
        delete headNode;
        return ans;
    }
};