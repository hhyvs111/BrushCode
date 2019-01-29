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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        //删除重复节点
        ListNode * copyHead = head;
        while(head->next != NULL)
        {
            if(head->val == head->next->val)
            {
                cout << head->val << endl;
                ListNode* DupNode = head->next;
                head->next = head->next->next;
                cout << head->val << endl;
                delete DupNode;
                // head = head->next;
                cout << head->val << endl;
            }
            else
            {
                head = head->next;
            }
        }
        return copyHead;
    }
};