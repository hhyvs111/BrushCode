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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //这个和那个差不多，但是要倒过来
        int len = postorder.size();
        if(len == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[len - 1]);
        vector<int> leftPost, rightPost, leftIn, rightIn;
        int rootIndex;
        for(int i = 0; i < len;i++)
        {
            if(postorder[len - 1] == inorder[i])
            {
                rootIndex = i;
                break;
            }
        }
        
        for(int i = 0 ; i < len;i++)
        {
            if(i < rootIndex)
            {
                //将跟节点的右边放过去
                leftPost.push_back(postorder[i]);
                leftIn.push_back(inorder[i]);
            }
            else if(i > rootIndex)
            {
                rightPost.push_back(postorder[i - 1]);
                rightIn.push_back(inorder[i]);
            }
        }
        root->left = buildTree(leftIn, leftPost);
        root->right = buildTree(rightIn, rightPost);
        return root;
    }
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //其实就是上面的版本简化了一下
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    //重载一下
    TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) {
        //如果越界了那么直接返回null
        //这里的right是最左，left是最右
        if (iLeft > iRight || pLeft > pRight) return NULL;
        TreeNode *cur = new TreeNode(postorder[pRight]);
        int i = 0;
        //找到中点
        for (i = iLeft; i < inorder.size(); ++i) {
            if (inorder[i] == cur->val) break;
        }
        //如果根节点就是左边起始点的话，那么拆分的话左边序列应该为空集，此时i - iLeft 为0， pLeft + 0 - 1 < pLeft, 那么再递归调用时就会返回NULL, 成立。如果根节点是左边起始点紧跟的一个，那么i - iLeft 为1， pLeft + 1 - 1 = pLeft，再递归调用时还会生成一个节点，就是pLeft位置上的节点，为原二叉树的一个叶节点。
        cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
        cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
        return cur;
    }
};