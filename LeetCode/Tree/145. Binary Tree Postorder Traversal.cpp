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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return ans;
        postOrder(root);
        
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            root = s.top();
            //取出来的肯定是有值的
            if(root->left != NULL)
            {
                //如果访问过了要给其加一个标记啊。
                s.push(root->left);
                //置为空，则不再访问
                root->left = NULL;
                continue;
            }
            if(root->right != NULL)
            {
                s.push(root->right);
                root->right = NULL;
                continue;
            }
            ans.push_back(root->val);
            s.pop();
        }
        return ans;
    }
    void postOrder(TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left != NULL) postOrder(root->left);
        if(root->right != NULL) postOrder(root->right);
        ans.push_back(root->val);
    }
};