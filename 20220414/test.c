#define _CRT_SECURE_NO_WARNINGS 1


//leetcode145. 二叉树的后序遍历 迭代
//int* postorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    *returnSize = 0;
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int* ret = (int*)malloc(sizeof(int) * 101);
//    struct TreeNode* a[101];
//    int i = 0;
//    struct TreeNode* head = root;
//    struct TreeNode* Save = NULL;
//    while (head != NULL || i)
//    {
//        while (head != NULL)
//        {
//            a[i++] = head;
//            head = head->left;
//        }
//        head = a[--i];
//        if (head->right == NULL || head->right == Save)
//        {
//            ret[(*returnSize)++] = head->val;
//            Save = head;
//            head = NULL;
//        }
//        else
//        {
//            a[i++] = head;
//            head = head->right;
//
//        }
//    }
//    return ret;
//}

//leetcode94. 二叉树的中序遍历
//int* inorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    *returnSize = 0;
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int* ret = (int*)malloc(sizeof(int) * 101);
//    struct TreeNode* a[101];
//    int i = 0;
//    struct TreeNode* head = root;
//    struct TreeNode* Save = NULL;
//    while (head != NULL || i > 0)
//    {
//        while (head != NULL)
//        {
//            a[i++] = head;
//            head = head->left;
//        }
//        head = a[--i];
//        ret[(*returnSize)++] = head->val;
//        head = head->right;
//    }
//    return ret;
//}