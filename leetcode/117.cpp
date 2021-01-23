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
    Node *q;
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        else
            root->next = NULL;
        connectNode(root);
        return root;
    }
    void connectNode(Node *node)
    {
        if (!node)
            return;
        Node *head = node;
        while (1)
        {
            if (node->left)
            {
                q = node->left;
                if (node->right)
                    q->next = node->right;
                else
                    q->next = findNext(node->next);
            }
            if (node->right)
            {
                q = node->right;
                q->next = findNext(node->next);
            }
            node = node->next;
            if (!node)
                break;
        }
        while (head)
        {
            if (head->left)
            {
                head = head->left;
                break;
            }
            if (head->right)
            {
                head = head->right;
                break;
            }
            head = head->next;
        }
        connectNode(head);
    }
    Node *findNext(Node *node)
    {
        if (!node)
            return NULL;
        if (node->left)
            return node->left;
        if (node->right)
            return node->right;
        return findNext(node->next);
    }
};