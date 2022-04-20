//
//
////leetcode104. 二叉树的最大深度
//struct TreeNode 
//{
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//int maxDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        int left = 1 + maxDepth(root->left);
//        int right = 1 + maxDepth(root->right);
//        return left > right ? left : right;
//    }
//}
//
//
//
////leetcode965. 单值二叉树
//bool isUnivalTree(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//    else if (root->left != NULL && root->left->val != root->val)
//    {
//        return false;
//    }
//    else if (root->right != NULL && root->right->val != root->val)
//    {
//        return false;
//    }
//    return isUnivalTree(root->right) && isUnivalTree(root->left);
//}


#include "BTree.h"