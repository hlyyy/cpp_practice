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
    bool isSymmetric(TreeNode *root)
    {
        return judgement(root, root);
    }
    bool judgement(TreeNode *leftnode, TreeNode *rightnode)
    {
        if (leftnode == nullptr && rightnode == nullptr)
            return true;
        if (leftnode == nullptr || rightnode == nullptr)
            return false;
        if (leftnode->val == rightnode->val && judgement(leftnode->left, rightnode->right) && judgement(leftnode->right, rightnode->left))
            return true;
        return false;
    }
};