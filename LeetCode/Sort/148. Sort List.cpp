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
    ListNode* sortList(ListNode* head) {
        //对list进行排序在常数级。那么就插入排序？这里主要是要在常数空间里面排序啊，说明不能用一些栈之类的！
        //这里要求的是O(nlogn), 那么只有归并排序和快排这些能满足这些需求了！
        if(!head || !head->next) return head;
        
        ListNode* slow = head, *fast = head, *pre = head;
        //找到链表的中点
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //这里为什么要用一个pre来记录倒数第二个节点呢？主要是要将链表一分为二，那么slow的尾部就不能有值了，要置为null
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        //头结点，不带数字,记录下头结点的位置
        ListNode* cur = dummy;
        //这里有点想合并两个有序列表
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                cur->next = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                l1 = l1->next;                    
            }
            cur = cur->next;
        }
        //这里剩下的就接到后面
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        
        return dummy->next;
        //这个递归的版本速度还快一些！
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};