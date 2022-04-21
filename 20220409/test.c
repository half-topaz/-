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

int main()
{
	BTDataType a[100];
	gets(a);
	int pi = 0;
	int n = sizeof(a)/sizeof(a[0]);
	BTNode* Top = BinaryTreeCreate(a, n, &pi);
	BinaryTreePrevOrder(Top);
	printf("\n");
	BinaryTreeInOrder(Top);
	printf("\n");
	BinaryTreePostOrder(Top);
	printf("\n");
	printf("层数：%d\n", BinaryTreeLevel(Top));
	printf("1层节点数：%d\n", BinaryTreeLevelKSize(Top, 1));
	printf("2层节点数：%d\n", BinaryTreeLevelKSize(Top, 2));
	printf("3层节点数：%d\n", BinaryTreeLevelKSize(Top, 3));
	printf("4层节点数：%d\n", BinaryTreeLevelKSize(Top, 4));
	printf("总节点数：%d\n", BinaryTreeSize(Top));
	printf("叶节点数：%d\n", BinaryTreeLeafSize(Top));
	BinaryTreeLevelOrder1(Top);
	BinaryTreeLevelOrder2(Top);
	printf("完全二叉树：%d\n", BinaryTreeComplete(Top));
	BTDataType x;
	while (scanf("%c", &x) != EOF)
	{
		printf("%p\n", BinaryTreeFind(Top, x));
	}
	BinaryTreeDestory(Top);
	Top = NULL;
	BinaryTreePrevOrder(Top);
	printf("\n");
	return 0;
}