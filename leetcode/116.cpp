/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;

        queue<Node *> q;
        Node *dummy = new Node(INT_MIN);
        Node *pre, *aft;
        q.push(root);
        q.push(dummy);
        pre = q.front();
        q.pop();
        if (root->left != NULL)
        {
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty())
        {
            aft = q.front();
            q.pop();
            if (aft == dummy)
            {
                pre->next = NULL;
                if (!q.empty())
                    q.push(dummy);
            }
            else
            {
                if (pre != dummy)
                    pre->next = aft;
                if (aft->left != NULL)
                {
                    q.push(aft->left);
                    q.push(aft->right);
                }
            }
            pre = aft;
        }

        return root;
    }
};