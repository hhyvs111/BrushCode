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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //反转链表输出其值？这里主要是看一下这个加减，然后要考虑这个进位。
        //还是要定义一个dummy类似的头结点，这样原来的头结点也好处理
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        //三者其一有值就进行循环，extra用来存放进位值
        while (l1 || l2 || extra) {
            //sum为l1和l2的值加上extra，如果为空则是0
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            //进位
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            //如果为空则一直是空
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};