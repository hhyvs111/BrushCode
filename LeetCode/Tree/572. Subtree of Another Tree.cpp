/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //判断是否是子树，主要是看这个节点的值吧！
        if(s == NULL)
            return false;
        //如果根节点不行，那么就传入其子节点。感觉我写的也是这么个意思！
        if(isSame(s, t)) return true;
        //这里分别判断左右，只要有就是符合的，两层递归
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    //代进来，这里可以判断子树
    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL)
            return false;
        if(s->val != t->val)
            return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};