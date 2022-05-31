/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> m;
        Node *l = head;
        while (l != nullptr)
        {
            Node *n = new Node(l->val);
            m[l] = n;
            l = l->next;
        }
        l = head;
        while (l != nullptr)
        {
            m[l]->next = m[l->next];
            m[l]->random = m[l->random];
            l = l->next;
        }
        return m[head];
    }
};