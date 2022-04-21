//
//
////leetcode104. ��������������
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
////leetcode965. ��ֵ������
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
	printf("������%d\n", BinaryTreeLevel(Top));
	printf("1��ڵ�����%d\n", BinaryTreeLevelKSize(Top, 1));
	printf("2��ڵ�����%d\n", BinaryTreeLevelKSize(Top, 2));
	printf("3��ڵ�����%d\n", BinaryTreeLevelKSize(Top, 3));
	printf("4��ڵ�����%d\n", BinaryTreeLevelKSize(Top, 4));
	printf("�ܽڵ�����%d\n", BinaryTreeSize(Top));
	printf("Ҷ�ڵ�����%d\n", BinaryTreeLeafSize(Top));
	BinaryTreeLevelOrder1(Top);
	BinaryTreeLevelOrder2(Top);
	printf("��ȫ��������%d\n", BinaryTreeComplete(Top));
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