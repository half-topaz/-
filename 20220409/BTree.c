#include "BTree.h"
#include "Queue.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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


// ����������
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


// �������ڵ���� = �������Ľڵ���� + �������Ľڵ���� + ����ڵ�   
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}


// ������Ҷ�ӽڵ���� = ��������Ҷ�ӽ����� + ��������Ҷ�ӽ�����
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


// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)//����û�нڵ�
	{
		return 0;
	}
	else if (k == 1)//��һ������ֻ��һ���ڵ�
	{
		return 1;
	}
	else
	{
		//���ĵ�K��Ľڵ���� = ��������K-1��Ľڵ���� + ��������K-1��Ľڵ����
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}


// ����������ֵΪx�Ľڵ�
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
		//�������������в�Ϊ�յĽ��������ȫΪ�ռ�������
		return left == NULL ? right : left;
	}
}


// ������ǰ�����   ��->��->��
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


// �������������   ��->��->��
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


// �������������   ��->��->��
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


//�������Ĳ���
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



//��ӡ��k��
void BinaryTreePrintKSize(BTNode* root, int k)
{
	if (root == NULL)//��������ӡ
	{
		return;
	}
	else if (k == 1)//��ӡ���ڵ�
	{
		printf("%c ",root->data);
	}
	else
	{
		//k������1��˵��������Ҫ��ӡ����һ�㣬�������²���
		BinaryTreePrintKSize(root->left, k - 1);
		BinaryTreePrintKSize(root->right, k - 1);
	}
}
// �������1����ȡ���Ĳ��������α���ÿһ��Ľڵ�
void BinaryTreeLevelOrder1(BTNode* root)
{
	//��ȡ���Ĳ���
	int n = BinaryTreeLevel(root);
	int k = 1;
	//�ӵ�һ�㿪ʼ���´�ӡ
	while (k <= n)
	{
		BinaryTreePrintKSize(root, k++);
	}
	printf("\n");
}


// �������2������
// ���ö����Ƚ��ȳ���ԭ���Ƚ����ڵ���ӣ�����ʱ�����ڵ�������ӽڵ���ӣ��Դ����ƣ�ֱ�������������ݣ���ʱ�������
// �ڹ�������ʱ�����ڵ�ĵ�ַ��ӣ������������ö�ͷ��ַ�ҵ����ڵ�������ӽڵ㡣
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


// �ж϶������Ƿ�����ȫ������
// ͬ�����ö��У���ͬ���ǣ�����ָ��Ҳ��ӣ�������ȫ�����������ʣ��������ȫ����������ô���ɵĶ�������Ч����Ӧ����������
// ��������г����˿�ָ��ʹ�����ݲ�������˵��������ȫ��������
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
		//�����ֿ�ָ��ʱ��������Ӳ������Դ�ʱ�������ݽ��м��
		if (head == NULL)
		{
			QueuePop(&q);
			break;
		}
		QueuePush(&q, head->left);
		QueuePush(&q, head->right);
		QueuePop(&q);
	}
	//���μ������У�����ڿ�ָ����ַǿ����ݣ�˵�����б���ָ��ضϣ���ʱ���в�������ȫ�����������������ص㣬˵��������ȫ������
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