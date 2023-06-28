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
/*
// Method 1
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead==NULL || secondHead==NULL)
        return NULL;

    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    while(temp1!=NULL && temp2!=NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp1==NULL)
            temp1 = secondHead;

    if(temp2==NULL)
        temp2 = firstHead;

    while(temp1!=temp2) {
        if(temp1==NULL)
            temp1 = secondHead;

        if(temp2==NULL)
            temp2 = firstHead;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1;
}
*/

// Method 2
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead==NULL || secondHead==NULL)
        return NULL;
    Node* a = firstHead;
    Node* b = secondHead;

    while(a!=b) {
        a = a==NULL ? secondHead : a->next;
        b = b==NULL ? firstHead : b->next;
    }

    return a;
}
