#include<bits/stdc++.h>
using namespace std;


struct ListNode {
	int data;
	ListNode *next;
	ListNode() : data(0), next(nullptr) {}
	ListNode(int x) : data(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
     	ListNode *slow = head,*fast = head;
       
    	while(fast!=nullptr && fast->next!=nullptr ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


void printList(struct ListNode *head){
	while(head!=NULL){
		cout<<head->data<< " ";
		head = head->next;
	}
}
int main(){
	int n;
	cin>>n;
	struct ListNode *head = NULL,*tail = NULL;
	int el;
	cin>>el;
	head = new ListNode(el);
	tail = head;
	for(int i=1;i<n;i++){
		cin>>el;
		tail->next = new ListNode(el);
		tail = tail->next;
	}
	Solution solve;
	head = solve.middleNode(head);
	printList(head);
	
}



