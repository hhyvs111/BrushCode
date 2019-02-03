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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //合并二叉树，如果有位置则值相加。用递归吗
        //如果t1为空那么t2的值放过来
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        t1->val += t2->val;
        //用递归解决，哎脑子是真的笨
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};