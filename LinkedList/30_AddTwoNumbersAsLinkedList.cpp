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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev,*head = l1;
        while(l1!=NULL && l2!=NULL){      
            int sum = l1->val+l2->val+carry;
            l1->val = sum%10;
            prev = l1;  
            carry = (sum>=10?1:0);
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1==NULL){
            prev->next = l2;
            l1 = prev->next;
        }
        while(l1!=NULL){
            int sum = l1->val+carry;
            l1->val = sum%10;
            carry = (sum>=10?1:0);
            prev = l1;
            l1 = l1->next;
        }
        if(carry!=0){
            ListNode *node = new ListNode(1);
            prev->next = node;
        }
        return head;
    }
};
