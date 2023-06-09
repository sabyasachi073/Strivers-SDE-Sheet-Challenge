#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

void traversal(BinaryTreeNode<int> *root, vector<vector<int>> &ans) {
    if(root==NULL)
        return;
    
    ans[1].push_back(root->data);
    traversal(root->left, ans);
    ans[0].push_back(root->data);
    traversal(root->right, ans);
    ans[2].push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans(3);
    traversal(root, ans);

    return ans;
}
