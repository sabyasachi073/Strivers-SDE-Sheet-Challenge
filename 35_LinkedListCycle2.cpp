/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    Node* fast=head, *slow=head;

    do {
        if(fast==NULL || fast->next==NULL)
            return NULL;

        slow = slow->next;
        fast = fast->next->next;
    }while(fast!=slow);

    slow = head;

    while(fast!=slow) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return fast;
}
