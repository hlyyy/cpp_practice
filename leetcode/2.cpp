/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *i = l1, pre;
        ListNode *j = l2;
        int c = 0;
        while (i != nullptr && j != nullptr)
        {
            i->val = i->val + j->val + c;
            c = i->val / 10;
            i->val %= 10;
            if (i->next == nullptr || j->next == nullptr)
                break;
            i = i->next;
            j = j->next;
        }
        if (i->next != nullptr)
        {
            i = i->next;
            while (1)
            {
                i->val = i->val + c;
                c = i->val / 10;
                i->val %= 10;
                if (i->next == nullptr)
                    break;
                i = i->next;
            }
            if (c != 0)
            {
                ListNode *l = new ListNode(c);
                i->next = l;
            }
        }
        if (j->next != nullptr)
        {
            j = j->next;
            while (1)
            {
                j->val = j->val + c;
                c = j->val / 10;
                ListNode *l = new ListNode(j->val % 10);
                i->next = l;
                i = i->next;
                if (j->next == nullptr)
                    break;
                j = j->next;
            }
            if (c != 0)
            {
                ListNode *l = new ListNode(c);
                i->next = l;
            }
        }
        if (c != 0)
        {
            ListNode *l = new ListNode(c);
            i->next = l;
        }
        return l1;
    }
};