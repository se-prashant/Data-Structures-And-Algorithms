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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast= head;
        ListNode *slow = head;
        while(fast != NULL && slow != NULL && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            break;
        }
        }
        if(fast==NULL || slow==NULL || fast->next==NULL) return NULL;
        slow = head;
        while(fast!=slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
