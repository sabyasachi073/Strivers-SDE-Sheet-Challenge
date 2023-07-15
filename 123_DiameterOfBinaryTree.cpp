/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int findDiameter(TreeNode<int> *root, int &diameter) {
    if(root==NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)
        return 0;

    int left = 0, right = 0;

    if(root->left)
        left = 1 + findDiameter(root->left, diameter);
    
    if(root->right)
        right = 1 + findDiameter(root->right, diameter);
    
    diameter = max(diameter, left+right);

    return max(left, right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
	findDiameter(root, diameter);
    return diameter;
}
