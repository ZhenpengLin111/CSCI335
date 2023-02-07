/**
 * Fill this out:
 *
 * @file
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sort.h" // include the sort library
#include <iostream>
using namespace std;

int main()
{
	// TODO: Test your sort library. This code will not be graded.
	int arr[6] = {2, 4, 5, 1, 3, 0};
	selection_sort(arr, 6);
	for(int i=0; i<6; i++)
	{
		cout << arr[i] <<endl;
	}

	int arr1[3] = {3, 2, 1};
	insertion_sort(arr1, 3);
	for(int i=0; i<3; i++)
	{
		cout << arr1[i] <<endl;
	}

	int arr2[5] = {8, 5, 9, 1, 4};
	merge_sort(arr2, 0, 4, 2);
	for(int i=0; i<5; i++)
	{
		cout << arr2[i] <<endl;
	}

	
}
