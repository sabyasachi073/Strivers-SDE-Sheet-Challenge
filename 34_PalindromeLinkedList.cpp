#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

/*
// Brute Force | TC-O(n) SC-O(n)
bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> arr;

    while(head!=NULL)
    {
        arr.push_back(head->data);
        head = head->next;
    }

    int left=0, right=arr.size()-1;
    
    while(left<right) {
        if(arr[left]!=arr[right])
            return false;
        left++;
        right--;
    }
    
    return true;
}
*/

// Optimized Approach | TC-O(n) SC-O(1)
LinkedListNode<int>* reverseList(LinkedListNode<int> *head) {
    LinkedListNode<int> *pre=NULL, *cur=NULL; 
    while(head!=NULL) {
        pre = cur;
        cur=head;
        head=head->next;
        cur->next = pre;
    }
    return cur;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL)
        return true;

    LinkedListNode<int> *dummy=head, *slow=head, *fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);
    slow=slow->next;

    fast = head;
    while(slow!=NULL) {
        if(slow->data != fast->data) {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
