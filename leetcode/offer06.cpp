/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *l = head;
        vector<int> v;
        while (l != nullptr)
        {
            v.insert(v.begin(), l->val);
            l = l->next;
        }
        return v;
    }
};