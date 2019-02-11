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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        //递归版本
        preOrder(root);
        
        //迭代版本
        TreeNode* node = root;
        if(node == NULL)
            return ans;
        stack<TreeNode*> s;
        s.push(node);
        while(!s.empty())
        {
            node = s.top();
            s.pop();
            ans.push_back(node->val);
            //要注意，先放right再放left
            if(node->right != NULL)
                s.push(node->right);
            if(node->left != NULL)
                s.push(node->left);
        }
        return ans;
    }
    void preOrder(TreeNode* root)
    {
        if(root == NULL)
            return;
        ans.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
        
    }
};