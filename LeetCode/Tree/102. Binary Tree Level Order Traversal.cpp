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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //二叉树的层序遍历，但是这里是将其存在vector里，主要是判断是同一层的level这个不是很好判断
        //用队列
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        level.push_back(root->val);
        ans.push_back(level);
        while(!q.empty())
        {
            // if(q.size() == 1){
            //     //如果大小为空，那么就是
            // }
            //每次都把同一层的清空
            vector<int> level;
            int size = q.size();
            //求出此层的size
            cout<<size<<endl;
            for(int i = 0; i < size;i++){
                TreeNode* head = q.front();
                if(head->left != NULL){
                    q.push(head->left);
                    level.push_back(head->left->val);
                }
                if(head->right != NULL){
                    q.push(head->right);
                    level.push_back(head->right->val);
                }
                q.pop();
            }
            if(!q.empty())
                ans.push_back(level);
        }
        return ans;
        
    }
};