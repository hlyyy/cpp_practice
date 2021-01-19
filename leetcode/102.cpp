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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> a;
        vector<int> b;
        if (root == NULL)
            return a;
        queue<TreeNode *> q;
        TreeNode *p;
        TreeNode *dummy = new TreeNode(INT_MIN);
        q.push(root);
        q.push(dummy);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p == dummy)
            {
                a.push_back(b);
                b.clear();
                if (!q.empty())
                    q.push(dummy);
            }
            else
            {
                b.push_back(p->val);
                if (p->left != NULL)
                {
                    q.push(p->left);
                }
                if (p->right != NULL)
                {
                    q.push(p->right);
                }
            }
        }
        return a;
    }
};