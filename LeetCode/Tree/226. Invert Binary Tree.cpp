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
    TreeNode* invertTree(TreeNode* root) {
        //反转二叉树，又是牛逼的题，又尼玛是递归，
        if(root == NULL)
            return NULL;
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    
        //队列
        if(root == NULL)
            return NULL;
        queue<TreeNode*> list;
        list.push(root);
        while(!list.empty())
        {
            TreeNode* now = list.front(); 
            //用完后出队
            list.pop();
            TreeNode* tmp = now->left;
            now->left = now->right;
            now->right = tmp;
            if(now->left != NULL)
                 list.push(now->left);
            if(now->right != NULL)
                list.push(now->right);
        }
        return root;
    }
};