
#include "BubbleSort.h"
#include <iostream>

 

void CK_SORT::BubbleSort(int* a, int size)
{
		 
	for (int i = 0; i < size -1; i++)
	{
		for (int j = 0; j < size -1; j++)
		{
			if ( *(a+j) > *(a+j+1)) {
				int temp = *(a + j + 1);
				*(a + j + 1) = *(a + j);
				*(a + j) = temp;
			}
		}

		for ( int  k = 0; k < size; k++)
		{
			std::cout << *(a + k) << " ";
		}

		std::cout << std::endl;
	}

}

void CK_SORT::test_BubbleSort()
{
	int k;
	int a[] = { 5,7,1,3,4,9,2,6,8.0 };
	const size_t sz = sizeof(a) / sizeof(a[0]);

	for (k = 0; k < sz; k++)
		std::cout << *(a + k) << " ";
	std::cout << std::endl;
	std::cout << "======================" << std::endl;
	BubbleSort(a, sz);
}

