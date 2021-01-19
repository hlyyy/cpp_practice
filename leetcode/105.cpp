/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *build(int preleft, int preright, int inleft, int inright, vector<int> &pre, vector<int> &in)
    {
        if (preleft > preright || inleft > inright)
            return NULL;
        TreeNode *root = new TreeNode(pre[preleft]);
        int rootin = inleft;
        while (pre[preleft] != in[rootin])
            rootin++;
        int left = rootin - inleft;
        root->left = build(preleft + 1, preleft + left, inleft, rootin - 1, pre, in);
        root->right = build(preleft + left + 1, preright, rootin + 1, inright, pre, in);
        return root;
    }
};