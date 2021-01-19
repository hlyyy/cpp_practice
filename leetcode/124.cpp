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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        maxSide(root);
        return max_sum;
    }
    int maxSide(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = max(0, maxSide(root->left));
        int right = max(0, maxSide(root->right));

        max_sum = max(max_sum, left + right + root->val);
        return (max(left, right) + root->val);
    }
};