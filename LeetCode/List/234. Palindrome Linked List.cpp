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
    bool isPalindrome(ListNode* head) {
        //若为空或者只有一个值，那么则直接返回正确
        if(!head || !head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << slow->val << endl;
        //走到了中间，定义两个节点用来反转。
        ListNode* newList = NULL;
        ListNode* tmp;
        ListNode* begin = slow;
        while(begin)
        {
            tmp = begin;
            begin = begin->next;
            tmp->next = newList;
            newList = tmp;
        }
        cout << newList->val << endl;
        //这里要判断头结点后面是否为空
        while(head->next)
        {
            if(head->val != newList->val)
                return false;
            head = head->next;
            newList = newList->next;
        }
        return true;
    }
};