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
    // 使用快慢指针判断是否有环
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            // slow == fast 时说明有环
            if (slow == fast) {
                ListNode * ans = head;
                // 从相遇点开始，slow 和从头结点开始的指针 ans 相遇时即为环的入口(使用数学证明)
                while (ans != slow) {
                    slow = slow->next;
                    ans = ans->next;
                }
                return ans;
            }
        }
        return NULL;
    }
};