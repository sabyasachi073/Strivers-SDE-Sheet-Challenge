#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    
    if(root==NULL)
        return ans;

    map<int, int> m; // map<HD, node>
    queue<pair<TreeNode<int>*, int>> q; // queue<node*, HD>

    q.push({root, 0});

    while(!q.empty()) {
        pair<TreeNode<int>*, int> temp = q.front();
        q.pop();
        TreeNode<int>* node = temp.first;
        int hd = temp.second;

        if(m.find(hd) == m.end()) {
            m[hd] = node->val;
        }

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
