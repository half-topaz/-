#define _CRT_SECURE_NO_WARNINGS 1
//LeetCode88合并数组
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    while (n)
//    {
//        if (m == 0)
//        {
//            nums1[n - 1] = nums2[n - 1];
//            n--;
//        }
//        else
//        {
//            if (nums1[m - 1] >= nums2[n - 1])
//            {
//                nums1[nums1Size - 1] = nums1[m - 1];
//                nums1Size--;
//                m--;
//            }
//            else
//            {
//                nums1[nums1Size - 1] = nums2[n - 1];
//                nums1Size--;
//                n--;
//            }
//        }
//    }
//}

//LeetCode26. 删除有序数组中的重复项
//int removeDuplicates(int* nums, int numsSize)
//{
//    int rec = 0;
//    int sea = 1;
//    while (sea != numsSize)
//    {
//        if (nums[rec] != nums[sea])
//        {
//            nums[rec + 1] = nums[sea];
//            rec++;
//            sea++;
//        }
//        else
//        {
//            sea++;
//        }
//    }
//    return;
//}

#include "SeqList.h"
int main()
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 0);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, -1);
	SeqListPushFront(&ps, -2);
	SeqListPushFront(&ps, -3);
	SeqListPrint(&ps);
	SeqListPopFront(&ps);
	SeqListPrint(&ps);
	SeqListPopBack(&ps);
	SeqListPrint(&ps);
	SeqListInsert(&ps, 3, 99);
	SeqListPrint(&ps);
	SeqListErase(&ps, 3);
	SeqListPrint(&ps);
	SeqListRevise(&ps, 4, 50);
	SeqListPrint(&ps);
	return 0;
}