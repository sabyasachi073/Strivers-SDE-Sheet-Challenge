/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    Node* dummy1 = head;
    Node* dummy2 = head;

    while(K>0)
    {
        dummy2=dummy2->next;
        K--;
    }

    if(dummy2==NULL)
    {
        dummy2 = dummy1;
        dummy1 = dummy1->next;
        free(dummy2);    
        return dummy1;
    }
    
    while(dummy2->next!=NULL) {
        dummy1=dummy1->next;
        dummy2=dummy2->next;
    }

    dummy2 = dummy1->next;
    dummy1->next  = dummy1->next->next;
    free(dummy2);

    return head;
}
