#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
/*
// Approach 1
bool isLeaf(TreeNode<int>* root) {
    if(root->left==NULL && root->right==NULL)
        return true;
    
    return false;
}

void traverseLeftBoundary(TreeNode<int>* root, vector<int> &ans) {
    if(root==NULL || isLeaf(root))
        return;
    
    ans.push_back(root->data);
    if(root->left) {
        traverseLeftBoundary(root->left, ans);
    }
    else {
        traverseLeftBoundary(root->right, ans);
    }
}

void traverseLeaf(TreeNode<int>* root, vector<int> &ans) {
    if(root==NULL)
        return;
    
    if(isLeaf(root))
        ans.push_back(root->data);

    if(root->left) {
        traverseLeaf(root->left, ans);
    }
    
    if(root->right) {
        traverseLeaf(root->right, ans);
    }
}

void traverseRightBoundary(TreeNode<int>* root, stack<int> &st) {
    if(root==NULL || isLeaf(root))
        return;
    
    st.push(root->data);
    if(root->right) {
        traverseRightBoundary(root->right, st);
    }
    else {
        traverseRightBoundary(root->left, st);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    ans.push_back(root->data);
    if(isLeaf(root))
        return ans;

    stack<int> st;

    traverseLeftBoundary(root->left, ans);
    traverseLeaf(root, ans);
    traverseRightBoundary(root->right, st);
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
*/

// Approach 2
bool isLeaf(TreeNode<int>* root) {
    if(root->left==NULL && root->right==NULL)
        return true;
    
    return false;
}

void traverseLeftBoundary(TreeNode<int>* root, vector<int> &ans) {
    TreeNode<int>* cur = root;

    while(cur) {
        if(!isLeaf(cur))
            ans.push_back(cur->data);
        
        if(cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void traverseLeaf(TreeNode<int>* root, vector<int> &ans) {
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }

    if(root->left) {
        traverseLeaf(root->left, ans);
    }
    
    if(root->right) {
        traverseLeaf(root->right, ans);
    }
}

void traverseRightBoundary(TreeNode<int>* root, vector<int> &ans) {
    if(root==NULL)
        return;
    
    stack<int> st;

    TreeNode<int>* cur = root;

    while(cur) {
        if(!isLeaf(cur))
            st.push(cur->data);
        
        if(cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    ans.push_back(root->data);
    if(isLeaf(root))
        return ans;

    traverseLeftBoundary(root->left, ans);
    traverseLeaf(root, ans);
    traverseRightBoundary(root->right, ans);

    return ans;
}
