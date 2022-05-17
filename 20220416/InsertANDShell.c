#include "Sort.h"

// ��������
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0;i < n;i++)
	{
		int ret = a[i];//i֮ǰ�������Ѿ�����
		int tail = i - 1;//�����������һλ
		//����
		while (tail >= 0 && a[tail] > ret)//��a[i]С������������ĳһλʱ�������λ�ÿ�ʼ������ȫ������ƶ�һλ
		{
			a[tail+1] = a[tail];
			tail--;
		}
		//���a[i]�������λ��
		a[tail + 1] = ret;
	}
}

// ϣ������
// �����ڲ�������ϣ�������ڱȽ����ݴ�Сʱ����ȡһ�����gap����ʹ���ݾֲ���������Сgap��ѭ������ֱ��gapΪ1
void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap;i < n;i++)
		{
			int ret = a[i];
			int tail = i - gap;
			while (tail >= 0 && a[tail] > ret)
			{
				a[tail + gap] = a[tail];
				tail -= gap;
			}
			a[tail + gap] = ret;
		}
	}
}
