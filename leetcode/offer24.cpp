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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *l = head;
        ListNode *p = head->next;
        while (l->next != nullptr)
            l = l->next;
        while (head != l)
        {
            head->next = l->next;
            l->next = head;
            head = p;
            p = p->next;
        }
        return l;
    }
};