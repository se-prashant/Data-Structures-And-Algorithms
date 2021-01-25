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
    ListNode* reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *temp = head;
        while(temp!=NULL){
            ListNode* x = temp->next;
            temp->next = prev;
            prev = temp;
            temp = x;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        int count =0;
        ListNode* tur = head,*hare =head;
        while(hare->next!=NULL && hare->next->next!=NULL){
            hare = hare->next->next;
            tur = tur->next;
        }
        tur->next = reverse(tur->next);
        tur = tur->next;
        while(tur!=NULL){  
            if(head->val != tur->val){
                return false;
            }
            head = head->next;
            tur = tur->next;
        }
        return true;
    }
};
