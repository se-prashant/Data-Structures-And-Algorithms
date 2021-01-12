/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//MEthod 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     unordered_set<ListNode *> st;
     while(headA!=NULL){
         st.insert(headA);
         headA = headA->next;
     }
     while(headB!=NULL){
        if(st.find(headB)!=st.end()) return headB;
         headB = headB->next;
     }
        return NULL;
    }
};

//Method 2 using distance

//Method 3 same as method 2 but smarter

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *dum1 = headA,*dum2 = headB;
        while(dum1!=dum2){
            dum1  = (dum1==NULL)?headB:dum1->next;
            dum2  = (dum2==NULL)?headA:dum2->next;
        }
        return dum1;
    }
};
    

