/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node *a,Node *b){
    Node *temp = new Node(0);
    Node *root =temp;
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a!=NULL) temp->bottom= a;
    else temp->bottom = b;
    return root->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
  if(root==NULL) return root;
  Node *head = flatten(root->next);
  return merge(root,head);
}


