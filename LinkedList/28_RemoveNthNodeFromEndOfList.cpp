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
        ListNode *slow,*fast;
        ListNode *start = new ListNode();
        start->next = head;
        slow = start;
        fast = start;
        for(int i=1;i<=n;i++){
          fast = fast->next;
        }
        // /return fast;
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // return slow;
        slow->next = slow->next->next;
        // return slow;
        return start->next;
    }
};
