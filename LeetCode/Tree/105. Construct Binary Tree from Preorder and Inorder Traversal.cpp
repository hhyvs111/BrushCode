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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0 , preorder.size() - 1, inorder, 0 , inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int leftPre, int rightPre,
                       vector<int>& inorder, int leftIn, int rightIn)
    {
        if(leftPre > rightPre || leftIn > rightIn)
            return NULL;
        TreeNode* root = new TreeNode(preorder[leftPre]);
        
        int mid = 0;
        for(mid = leftIn ;mid < rightIn; mid++)
        {
            if(inorder[mid] == preorder[leftPre])
                break;
        }
        //此时的mid就是中间位置
        //注意这个rightPre的位置，mid - leftIn就是左子树的长度,加上leftpre 的长度
        root->left = buildTree(preorder, leftPre + 1, leftPre + (mid - leftIn), inorder, leftIn, mid - 1 );
        root->right = buildTree(preorder, (mid - leftIn) + leftPre + 1, rightPre, inorder, mid + 1, rightIn);
        return root;
    }
        //用前序和中序构造二叉树
        //之前做过又忘了,还是递归
//         int lenIn = inorder.size();
//         if(lenIn == 0) return NULL;
//         TreeNode* root = new TreeNode(preorder[0]);
//         vector<int> leftPre, rightPre, leftIn, rightIn;
//         int rootIndex;
//         //找出pre第一个，也就是根节点
//         for(int i = 0;i < lenIn;i++)
//         {
//             if(preorder[0] == inorder[i])
//             {
//                 rootIndex = i;
//                 break;
//             }
//         }
//         for(int i = 0 ;i < lenIn;i++)
//         {
//             //二叉树的左边
//             if(i < rootIndex)
//             {
//                 //这里的i+1是因为要跳过根节点
//                 leftPre.push_back(preorder[i+1]);
//                 leftIn.push_back(inorder[i]);
//             }
            
//             else if(i > rootIndex)
//             {
//                 rightPre.push_back(preorder[i]);
//                 rightIn.push_back(inorder[i]);
//             }
                
//         }
//         root->left = buildTree(leftPre, leftIn);
//         root->right = buildTree(rightPre, rightIn);
//         return root;
    // }
};

//这个方法太垃圾了，时间上太慢了，不知道有没有好的方法，迭代？