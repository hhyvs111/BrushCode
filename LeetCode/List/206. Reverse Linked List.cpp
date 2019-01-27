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
    ListNode* reverseList(ListNode* head) {
        //经典题，反转链表
        //定义两个个节点
        ListNode* temp;
        ListNode* newList = NULL;
        while(head != NULL)
        {
            //此时temp指向的1
            temp = head;
            //为了不断开1和2的链接，先把head指向了2
            head = head->next;
            //1的下一个是newList也就是null
            temp->next = newList;
            //再将newlist等于temp，此时newlist为1->null
            newList = temp;
            
        }
        return newList;
    }
};