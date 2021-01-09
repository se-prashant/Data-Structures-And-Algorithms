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
   
    	if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *temp = NULL;
        if(l1->val > l2->val){
            ListNode *temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode *res = l1;
        while(l1!=NULL && l2!=NULL){
            ListNode *temp = NULL;
            while(l1!=NULL && (l1->val)<=(l2->val)){
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            ListNode *swp = l1;
            l1 = l2;
            l2 = swp;
        }
        return res;
    }
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL,*temp=NULL;
        while(l1!=NULL && l2!=NULL){
            int val1 = l1->val;
            int val2 = l2->val;
            if(val1<=val2){
                if(head==NULL){
                    head = new ListNode(val1);
                    temp = head;
                }else{
                    temp->next = new ListNode(val1);
                    temp = temp->next;
                }
                 l1 =l1->next;
            }else{
                if(head==NULL){
                    head = new ListNode(val2);
                    temp = head;
                }else{
                    temp->next = new ListNode(val2);
                    temp = temp->next;
                }
                l2 = l2->next;
            }
        }
        while(l1!=NULL){
                int val1 = l1->val;
                 if(head==NULL){
                    head = new ListNode(val1);
                    temp = head;
                }else{
                    temp->next = new ListNode(val1);
                     temp = temp->next;
                }
                 l1 =l1->next;
                 
              
        }
        while(l2!=NULL){
                int val2 = l2->val;
                 if(head==NULL){
                    head = new ListNode(val2);
                    temp = head;
                }else{
                    temp->next = new ListNode(val2);
                    temp = temp->next;
                }
                 l2= l2->next;
        }
        
        return head;
    }
};
