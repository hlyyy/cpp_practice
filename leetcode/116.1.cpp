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
        else
            root->next = NULL;
        connectNode(root);
        return root;
    }
    void connectNode(Node *root)
    {
        if (root == NULL || root->left == NULL)
            return;
        root->left->next = root->right;
        if (root->next != NULL)
            root->right->next = root->next->left;
        else
            root->right->next = NULL;

        connectNode(root->left);
        connectNode(root->right);
    }
};