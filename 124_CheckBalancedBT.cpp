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
int balancedHeight(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return 0;
    
    int left = balancedHeight(root->left);
        
    int right = balancedHeight(root->right);

    if(left==-1 || right==-1)
        return -1;
    
    if(abs(left-right)>1)
        return -1;
    
    return max(left, right)+1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return balancedHeight(root) != -1;
}
