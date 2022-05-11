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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = lists.size();
        if (l == 0)
            return nullptr;
        ListNode* h0;
        ListNode* head;
        int n = 0;
        for (; n < l; n++) {
            head = lists[n];
            if (head != nullptr)
                break;
        }
        for (int i = n+1; i < l; i++) {
            h0 = head;
            ListNode* hi = lists[i];
            if (hi == nullptr)
                continue;
            if (hi->val < h0->val) {
                ListNode* ll = new ListNode(hi ->val);
                ll -> next = h0;
                head = ll;
                h0 = head;
                hi = hi -> next;
            }
            while (h0 -> next != nullptr && hi != nullptr) {
                while (h0 -> next != nullptr && h0 -> next -> val < hi -> val) 
                    h0 = h0 ->next;
                if (h0 == nullptr) 
                    break;
                ListNode* ll = new ListNode(hi->val);
                ll -> next = h0 -> next;
                h0 -> next = ll;
                h0 = h0 -> next;
                hi = hi -> next;
            }
            if (h0 -> next == nullptr) 
                h0 -> next = hi;
        }
        return head;
    }
};