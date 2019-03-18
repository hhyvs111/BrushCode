/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //删除所有值为val的节点
        ListNode* cur = new ListNode(-1);
        cur->next = head;
        ListNode* dummy = cur;
        while(cur->next)
        {
            if(cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};