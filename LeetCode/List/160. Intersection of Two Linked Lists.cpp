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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //题目要求o(n)和o(1),那么用map不行啊
        //牛逼版本，两个指针同时走，若A的长度比B的短，当1走到A的尽头时，2还在走。此时将1走B的路，当2走完时走A的路，它们会在插入点相遇。因为它们走的长度都是一样，所以会在同一点相遇。当没有交叉点时它们会在null相遇，因为二者都会指向空，但是好像多了不必要的开销。
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1?cur1->next:headB;
            cur2 = cur2?cur2->next:headA;
        }
        return cur1;
        
        //还有一种方法是将两个链表右对齐，然后将长的移动到短的起点，同时开始遍历。
        
        
        //找到插入的节点？主要是他们共享一个节点，如何找出？将所有节点放入unordered_map?
        unordered_map<ListNode *, int> nodeMap;
        //先将a都插入到map
        while(headA != NULL)
        {
            nodeMap.insert({headA,0});
            headA = headA->next;
        }
        while(headB != NULL)
        {
            if(!nodeMap.insert({headB,0}).second)
                return headB;
            headB = headB->next;
        }
        return NULL;
        
    }
};