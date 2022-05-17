#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void Swap(int* a, int* b);

// √∞≈›≈≈–Ú
void BubbleSort(int* a, int n);

// øÏÀŸ≈≈–Úµ›πÈ µœ÷
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSort3(int* a, int left, int right);

// øÏÀŸ≈≈–Ú ∑«µ›πÈ µœ÷
void QuickSortNonR(int* a, int left, int right);

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

// ∂—≈≈–Ú
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);
