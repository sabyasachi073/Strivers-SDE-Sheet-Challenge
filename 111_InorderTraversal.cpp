#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorderTraversal(TreeNode* root, vector<int> &ans) {
    if(root==NULL)
        return;

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorderTraversal(root, ans);

    return ans;
}
