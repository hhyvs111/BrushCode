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
    ListNode* middleNode(ListNode* head) {
        //返回链表中间的值，如果知道长度了那么比较好返回，如果事先走一遍知道长度了，那么再返回从头开始找，是不是有点浪费时间？
        if(!head)
            return NULL;
        ListNode* headCopy = head;
        int cnt = 0;
        while(head != NULL)
        {
            cnt++;
            head = head->next;
        }
        for(int i = 0 ; i < cnt/2 ; i++)
            headCopy = headCopy->next;
        return headCopy;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            //用快慢指针，快指针一次走两步，慢的指针一次走一步。当快指针到结尾的时候，慢指针就会处于中间的位置。
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};