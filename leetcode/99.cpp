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
    TreeNode *a = nullptr, *b = nullptr, *pre;
    int temp;
    void recoverTree(TreeNode *root)
    {
        inorder(root);

        temp = a->val;
        a->val = b->val;
        b->val = temp;
        return;
    }

    void inorder(TreeNode *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        if (pre == nullptr)
            pre = node;
        if (node->val < pre->val)
        {
            if (a == nullptr)
                a = pre;
            b = node;
        }
        pre = node;
        inorder(node->right);
    }
};