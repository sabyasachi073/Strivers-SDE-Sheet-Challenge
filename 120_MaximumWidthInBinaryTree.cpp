#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    
    int ans=0;
    queue<pair<TreeNode<int>*, int>> q; // queue<Node*, levelIindexNo>

    q.push({root, 1});

    while(!q.empty()) {
        int last;
        int size = q.size();
        int k = 1;
        for(int i=0; i<size; i++) {
            TreeNode<int>* node = q.front().first;
            int curIdx = q.front().second;
            q.pop();

            if(i==size-1)
                last = curIdx;
            

            if(node->left) {
                q.push({node->left, k++});
            }
            

            if(node->right) {
                q.push({node->right, k++});
            }

        }
        ans = max(ans, last);
    }

    return ans;
}
