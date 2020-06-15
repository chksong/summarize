
#include "BubbleSort.h"
#include <iostream>
#include <iostream>
#include <iomanip>
 
///1  Bubble sort is a simple sorting algorithm that works by repeatedly stepping through the list to be sorted, 
/// comparing each pair of adjacent items and swapping them if they are in the wrong order. 
//  The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.

//  ð��������һ�ּ򵥵������㷨���乤��ԭ���Ƿ�������Ҫ������б��Ƚ�ÿ����������˳������򽻻����ǡ�
//  �ظ�ͨ���б�ֱ������Ҫ����Ϊֹ��������б�������

/// [CK] �൱����ȡԪ��һ����һ��ѭ��ֻ�ܰ� �����������ֵ��������ҪN��ѭ�� 
void CK_SORT::BubbleSort(int* a, int size)
{
	for (int i = 0; i < size -1; i++)
	{
		for (int j = 0; j < size -1; j++)   //ÿ�αȽ����ڵ�Ԫ�أ��������ͽ�������
		{
			if ( *(a+j) > *(a+j+1)) {
				int temp = *(a + j + 1);
				*(a + j + 1) = *(a + j);
				*(a + j) = temp;
			}
		}

		std::cout << "[" << i << "]";
		for ( int  k = 0; k < size; k++)
		{
			std::cout << std::setw(3)  <<*(a + k) ;
		}

		std::cout << std::endl;
	}

}

template<typename T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}


void CK_SORT::InsertSort(int a[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int j = i;
		while (j > 0 && a[j] < a[j-1])
		{
			swap(a[j], a[j - 1]);
			j--;
		}

		std::cout << std::endl;
		std::cout << "[" << i << "]";
		for (int k = 0; k < sz; k++) {
			std::cout << std::setw(3) << a[k];
		}
	}
}



void CK_SORT::test_BubbleSort()
{
	int k;
	int a[] = { 5,7,1,3,4,9,2,6,8,0 };
	const size_t sz = sizeof(a) / sizeof(a[0]);

	for (k = 0; k < sz; k++)
		std::cout << std::setw(3)  << *(a + k)  ;
	std::cout << std::endl;
	std::cout << "\n test_BubbleSort ======================" << std::endl;
	BubbleSort(a, sz);
}



void CK_SORT::test_InsertSort()
{
	std::cout << " \n test_InsertSort======================" << std::endl;
	//int a[] = { 15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14 };
	int a[] = { 5,7,1,3,4,9,2,6,8,0 };
	int size = sizeof(a) / sizeof(int);
	for (int i = 0; i < size; i++) std::cout  << std::setw(3) << a[i];
	InsertSort(a, size);
	std::cout << std::endl;
}
