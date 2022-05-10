#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//leetcode 100 相同的树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p != NULL && q != NULL)
//    {
//        if (p->val != q->val)
//        {
//            return false;
//        }
//        else
//        {
//            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//        }
//    }
//    else if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

//leetcode 101 对称二叉树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p != NULL && q != NULL)
//    {
//        if (p->val != q->val)
//        {
//            return false;
//        }
//        else
//        {
//            return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
//        }
//    }
//    else if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//bool isSymmetric(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//    else
//    {
//        return isSameTree(root->left, root->right);
//    }
//}


//leetcode144. 二叉树的前序遍历
//模拟栈实现前序遍历
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int i = 0;
//    int* a = (int*)malloc(sizeof(int) * 100);
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return a;
//    }
//    else
//    {
//        struct TreeNode** ret = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
//        int size = 0;
//        ret[size] = root;
//        size++;
//        while (size)
//        {
//            struct TreeNode* head = ret[--size];
//            a[i] = head->val;
//            i++;
//            if (head->right != NULL)
//            {
//                ret[size] = head->right;
//                size++;
//            }
//            if (head->left != NULL)
//            {
//                ret[size] = head->left;
//                size++;
//            }
//        }
//        free(ret);
//        *returnSize = i;
//        return a;
//    }
//}


//leetcode572. 另一棵树的子树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p != NULL && q != NULL)
//    {
//        if (p->val != q->val)
//        {
//            return false;
//        }
//        else
//        {
//            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//        }
//    }
//    else if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//    if (root == NULL || subRoot == NULL)
//    {
//        return false;
//    }
//    else
//    {
//        if (isSameTree(root, subRoot))
//        {
//            return true;
//        }
//        else
//        {
//            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//        }
//    }
//}

//leetcode226. 翻转二叉树
//struct TreeNode* invertTree(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    root->left = invertTree(root->left);
//    root->right = invertTree(root->right);
//    struct TreeNode* ret;
//    ret = root->left;
//    root->left = root->right;
//    root->right = ret;
//    return root;
//}