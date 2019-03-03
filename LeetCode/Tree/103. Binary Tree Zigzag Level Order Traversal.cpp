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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        //这里不同于那个层次遍历，是要倒过来，走z字形那么要一层用栈一层用这个队列？感觉好像还行哦。
        //直接用队列，然后reverse好了
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(vector<int> {root->val});
        bool isReverse = true;
        while(!q.empty())
        {
            vector<int> sub;
            int size = q.size();
            for(int i = 0;i < size;i++)
            {
                TreeNode* node = q.front();
                if(node->left) 
                {
                    q.push(node->left);
                    sub.push_back(node->left->val);
                }
                if(node->right)
                {
                    q.push(node->right);
                    sub.push_back(node->right->val);
                }
                q.pop();
                
            }
            //每层判断一下，是否是需要反转。感觉算是取巧了，知道正确的做法是啥
             if(isReverse)
             {
                    reverse(sub.begin(), sub.end());
             }
             isReverse = !isReverse;
             if(!q.empty())
                ans.push_back(sub);
        }
        return ans;
        
    }
};