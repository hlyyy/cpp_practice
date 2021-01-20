/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
    }
    TreeNode *build(int inleft, int inright, int postleft, int postright, vector<int> &in, vector<int> &post)
    {
        if (inleft > inright || postleft > postright)
            return nullptr;
        TreeNode *p = new TreeNode(post[postright]);
        int rootin = inright;
        while (p->val != in[rootin] && rootin >= inleft)
            rootin--;
        int right = inright - rootin;
        p->left = build(inleft, rootin - 1, postleft, postright - 1 - right, in, post);
        p->right = build(rootin + 1, inright, postright - right, postright - 1, in, post);
        return p;
    }
};