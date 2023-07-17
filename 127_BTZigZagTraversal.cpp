#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

/*
// Approach 1
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;

    if(root==NULL)
        return ans;
        
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        
        for(int i=0; i<size; i++) {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();

            int index = leftToRight ? i : (size-1-i);
            row[index] =  temp->data;

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
        }
        ans.insert(ans.end(), row.begin(), row.end());
        leftToRight = !leftToRight;
    }
    return ans;
}
*/

// Approach 2
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;

    if(root==NULL)
        return ans;
        
    deque<BinaryTreeNode<int>*> dq;
    dq.push_back(root);
    bool leftToRight = true;

    while(!dq.empty()) {
        int size = dq.size();
        
        for(int i=0; i<size; i++) {
            if(leftToRight) {
                BinaryTreeNode<int> *node = dq.front();
                dq.pop_front();
                ans.push_back(node->data);

                if(node->left) 
                    dq.push_back(node->left);
                if(node->right) 
                    dq.push_back(node->right);
            }
            
            else {
                BinaryTreeNode<int> *node = dq.back();
                dq.pop_back();
                ans.push_back(node->data);

                if(node->right) 
                    dq.push_front(node->right);
                if(node->left) 
                    dq.push_front(node->left);
            }
            
        }

        leftToRight = !leftToRight;
    }
    return ans;
}
