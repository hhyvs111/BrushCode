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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //最近祖先，用递归做吧
        //边界条件，如果root == p或者  root 为空那么就返回root
        if( !root || root == p || root == q) return root;
        
        //递归求其左节点
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        //递归求其右节点
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //如果左右节点都存在，那么当前root就是共同祖先
        if(left && right) return root;
        //如果其中一个不存在，返回存在的那个
        return left ? left : right;
        
    }
};