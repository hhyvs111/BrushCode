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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //有点像合并两个有序数组，主要是处理一下链表
        //用多余的空间，这个是个最小值
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while(l1 && l2)
        {
            //用额外数组，哪个小放哪个
            if(l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l2 != NULL)
            tail->next = l2;
        if(l1 != NULL)
            tail->next = l1;
        return dummy.next;



    }
};
//递归版本，感觉很精妙。递归这个东西是真的搞不懂，但是还是可以看出一些东西出来的。
//首先子问题是两个数比较大小，这里是将子序列传入，最后会剩下两个数的比较。因为有递归栈存储原来的数据，所以也不会丢失。
//如果l1比l2小，那么l1的下一位就是l1->next和l2的位数。依次递归。当其中一个是null时，会返回最终的值。
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};


//         while(l1->next != NULL && l2->next != NULL)
//         {
//             //l2大于l1
//             if(l2->val < l1->val)
//             {
//                 ListNode * tmp = l2;
//                 l2 = l2->next;
//                 tmp->next = l1;
//                 l1 = tmp;
//             }

//             else if(l2->val >= l1->val && l2->val <= l1->next->val)
//             {
                
//             }
            
//             if(l2->val >= l1->val && l2->val <= l1->next->val)
//             {
//                 ListNode* tmp = l2;
//                 l2 = l2->next;
//                 cout <<"tmp:" << tmp->val << " L2: " << l2->val << endl;
//                 tmp->next = l1->next;
//                 l1->next = tmp; 
//                 cout << "l1: " << l1->val << endl;
//                 l1 = l1->next;
//                 cout << "Twol1: " << l1->val << endl;
//                 l1 = l1->next;
//                 cout<< "last " << l1->val << " " << l2->val << endl;
                
//             }
//             else
//                 l1 = l1->next;     
//         }
//         if(l2 != NULL)
//             l1->next = l2;
//         return l1;