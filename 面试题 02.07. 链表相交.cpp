/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 双指针法，题目给的例题中两链表已相交。链表相交不代表只要值相同就行，值相等的结点不一定是同一个结点
    // 由于相交后结点元素都相同，若链表 A 长度为 m, 链表 B 长度为 n (m > n)， 那么链表 A 至少从位置 0 + (m - n) 开始才能保证能够同步相交
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 定义 A、B 的当前结点
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;

        // 测量 A、B 链长度
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }

        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;

        // 让 A 成为最长链
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // 让最长链移到与段链相同位置
        int diff = lenA - lenB;
        while (diff) {
            curA = curA->next;
            diff--;
        }

        // 检查当前结点是否为相交结点
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};