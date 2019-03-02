/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         //在二叉排序中找到指定节点然后删除，并重建树
//         if(root == NULL) return NULL;
        
//         //这里要设定一个头结点，因为根节点也要判断
//         TreeNode* head = new TreeNode(-1);
//         head->left = root;
//         TreeNode* father = head;
//         //因为头结点也可能更新，那么定义一个father用来保存上一个节点
//         while(root)
//         {
//             //如果找到了节点则删除
//             //有三种情况，一种是叶子子节点直接删除
//             //一种是有左右子树，则找到被删除节点的右子树的最左节点
//             //一种是只有一个子节点，直接删除后将其接到其父节点
//             //这个父节点怎么保存？那么只有用队列了
//             cout<<root->val << endl;
//             if(root->val == key)
//             {
//                 //有两个节点
//                 if(root->left != NULL && root->right != NULL)
//                 {
//                     cout<< "test" <<endl;
//                     TreeNode* replace = root->right;
//                     father = root;
//                     while(replace->left != NULL) 
//                     {
//                         father = replace;
//                         replace = replace->left;
//                     }
//                     //找到最左节点
//                     root->val = replace->val;
//                     //这里不能直接置为空，要其父节点置为空
//                     if(father != root)
//                         father->left = NULL;
//                     else
//                         father->right = NULL;
//                 }
//                 else if(root->left != NULL || root->right != NULL)
//                 {
//                     if(root->left != NULL)
//                     {
//                         if(father->left == root)
//                             father->left = root->left;
//                         else
//                             father->right = root->left;
//                     }
//                     if(root->right != NULL)
//                     {
//                         if(father->left == root)
//                             father->left = root->right;
//                         else
//                             father->right = root->right;
//                     }
//                 }
//                 else
//                 {
//                     cout << "father- " << father->val;
//                     if(father->left == root)
//                         father->left == NULL;
//                     else
//                         father->right = NULL;
//                     root = NULL;
//                     free(root);
//                 }
                
//                 break;
//             }
//             else if(root->val < key)
//             {
//                 father = root;
//                 root = root->right;
//             }
//             else if(root->val > key)
//             {
//                 father = root;
//                 root = root->left;
//             }
               
//         }
//         return head->left;
//     }
// };

//用递归就不用保存它的父节点了
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if(root->val == key)
        {
            //尼玛还有顺序么，怎么判断条件不是很对啊，先判断这个全为空的情况
            if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            /* 1 child case */
            if (!root->left || !root->right) {
                TreeNode *ret = root->left ? root->left : root->right;
                delete(root);
                return ret;
            }
            
            if(root->right && root->left)
            {
                TreeNode *tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                //通过再次调用，将被调换的节点删掉
                root->right = deleteNode(root->right, root->val);
            }

        }
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else
            root->left = deleteNode(root->left, key);
        
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (!root) return NULL;
//         if (root->val > key) {
//             root->left = deleteNode(root->left, key);
//         } else if (root->val < key) {
//             root->right = deleteNode(root->right, key);
//         } else {
//             if (!root->left || !root->right) {
//                 root = (root->left) ? root->left : root->right;
//             } else {
//                 TreeNode *cur = root->right;
//                 while (cur->left) cur = cur->left;
//                 root->val = cur->val;
//                 root->right = deleteNode(root->right, cur->val);
//             }
//         }
//         return root;
//     }
// };

//看了答案，怎么这么简洁，哎我真的是蠢！