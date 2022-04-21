#include "BTree.h"
#include "Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NewNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	NewNode->data = a[*pi];
	(*pi)++;
	if (*pi < n)
	{
		NewNode->left = BinaryTreeCreate(a, n, pi);
		NewNode->right = BinaryTreeCreate(a, n, pi);
	}
	return NewNode;
}


// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL) 
	{
		return;
	}
	else
	{
		BinaryTreeDestory(root->left);
		BinaryTreeDestory(root->right);
		free(root);
	}
}


// 二叉树节点个数 = 左子树的节点个数 + 右子树的节点个数 + 自身节点   
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}


// 二叉树叶子节点个数 = 左子树的叶子结点个数 + 右子树的叶子结点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)//空树没有节点
	{
		return 0;
	}
	else if (k == 1)//第一层有且只有一个节点
	{
		return 1;
	}
	else
	{
		//树的第K层的节点个数 = 左子树第K-1层的节点个数 + 右子树第K-1层的节点个数
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}


// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->data==x)
	{
		return root;
	}
	else
	{
		BTNode* left = BinaryTreeFind(root->left, x);
		BTNode* right = BinaryTreeFind(root->right, x);
		//返回左右子树中不为空的结果，或者全为空即不存在
		return left == NULL ? right : left;
	}
}


// 二叉树前序遍历   中->左->右
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}


// 二叉树中序遍历   左->中->右
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}


// 二叉树后序遍历   左->右->中
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}


//计算树的层数
int BinaryTreeLevel(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		int left = BinaryTreeLevel(root->left);
		int right = BinaryTreeLevel(root->right);
		return 1 + (left > right ? left : right);
	}
}



//打印第k层
void BinaryTreePrintKSize(BTNode* root, int k)
{
	if (root == NULL)//空树不打印
	{
		return;
	}
	else if (k == 1)//打印根节点
	{
		printf("%c ",root->data);
	}
	else
	{
		//k不等于1，说明还不是要打印的那一层，继续向下查找
		BinaryTreePrintKSize(root->left, k - 1);
		BinaryTreePrintKSize(root->right, k - 1);
	}
}
// 层序遍历1，获取树的层数，依次遍历每一层的节点
void BinaryTreeLevelOrder1(BTNode* root)
{
	//获取树的层数
	int n = BinaryTreeLevel(root);
	int k = 1;
	//从第一层开始向下打印
	while (k <= n)
	{
		BinaryTreePrintKSize(root, k++);
	}
	printf("\n");
}


// 层序遍历2：队列
// 利用队列先进先出的原则，先将根节点入队，出队时将根节点的左右子节点入队，以此类推，直到队列内无数据，此时遍历完成
// 在构建队列时，将节点的地址入队，这样可以利用队头地址找到根节点的左右子节点。
void BinaryTreeLevelOrder2(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	
	while (!QueueEmpty(&q))
	{
		QDataType head = QueueFront(&q);
		if (head->left != NULL)
		{
			QueuePush(&q, head->left);
		}
		if (head->right != NULL)
		{
			QueuePush(&q, head->right);
		}
		printf("%c ", head->data);
		QueuePop(&q);
	}
	QueueDestroy(&q);
	printf("\n");
}


// 判断二叉树是否是完全二叉树
// 同样利用队列，不同的是，将空指针也入队，根据完全二叉树的性质，如果是完全二叉树，那么构成的队列内有效数据应该是连续的
// 如果队列中出现了空指针使得数据不连续，说明不是完全二叉树。
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		QDataType head = QueueFront(&q);
		//当发现空指针时，结束入队操作，对此时队内数据进行检查
		if (head == NULL)
		{
			QueuePop(&q);
			break;
		}
		QueuePush(&q, head->left);
		QueuePush(&q, head->right);
		QueuePop(&q);
	}
	//二次检查过程中，如果在空指针后发现非空数据，说明队列被空指针截断，此时队列不满足完全二叉树数据连续的特点，说明不是完全二叉树
	while (!QueueEmpty(&q))
	{
		QDataType head = QueueFront(&q);
		if (head != NULL)
		{
			QueueDestroy(&q);
			return 0;
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 1;
}