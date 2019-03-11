/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int inLen = vin.size();
        //若为空则是空节点。
        if(inLen==0)
                return NULL;
        vector<int> leftPre, rightPre, leftIn, rightIn;
        //前序遍历的第一个节点就是根节点
        TreeNode* head = new TreeNode(pre[0]);
        int rootIndex;
        for(int i = 0;i < inLen;i++)
        {
            if(pre[0] == vin[i])
            {
                rootIndex = i;
                break;
            }
        }
        //将序列分离为左右
        for(int i = 0;i < inLen;i++)
        {
            if(i < rootIndex)
            {
                leftIn.push_back(vin[i]);
                leftPre.push_back(pre[i + 1]);
            }
            else if(i > rootIndex)
            {
                rightIn.push_back(vin[i]);
                rightPre.push_back(pre[i]);
            }
        }
        head->left = reConstructBinaryTree(leftPre, leftIn);
        head->right = reConstructBinaryTree(rightPre, rightIn);
        return head;

    }
};