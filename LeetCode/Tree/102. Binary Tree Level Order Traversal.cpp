class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for(int i = 0;i < size;i++)
            {
                TreeNode* now = q.front();
                level.push_back(now->val);
                if(now->left) 
                    q.push(now->left);
                if(now->right)
                    q.push(now->right);
                q.pop();
            }
            ans.push_back(level);
        }
        return ans;
    }
};