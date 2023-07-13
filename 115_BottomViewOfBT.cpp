#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    
    if(root==NULL)
        return ans;

    map<int, int> m; // map<HD, node>
    queue<pair<BinaryTreeNode<int>*, int>> q; // queue<node*, HD>

    q.push({root, 0});

    while(!q.empty()) {
        pair<BinaryTreeNode<int>*, int> temp = q.front();
        q.pop();
        BinaryTreeNode<int>* node = temp.first;
        int hd = temp.second;

        m[hd] = node->data;

        if(node->left)
            q.push({node->left, hd-1});
        if(node->right)
            q.push({node->right, hd+1});
    }
    
    for(auto i: m) {
        ans.push_back(i.second);
    }

    return ans;
}
