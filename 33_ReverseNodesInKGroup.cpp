#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	    if(head==NULL || (n==1 && b[0]<=1))
            return head;

        Node* dummy = new Node(0);
        dummy->next = head;

        Node *prev = dummy, *cur = dummy, *nxt = dummy;

        int count = 0;

        while(cur->next != NULL) {
            cur = cur->next;
            count++;
        }
		
		int i=0;

        while(i<n && count>0) {
			if(b[i]==0){
				i++;
				continue;
			}

            cur = prev->next;
            nxt = cur->next;

            for(int j=1; j<b[i] && nxt!=NULL; j++) {
                cur->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = cur->next;
            }
            prev = cur;
            count = count-b[i];
			i++;
        }
        return dummy->next;
}
