/**
 * TODO: Fill this out:
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

#include "sort.h"

#include <utility> // for std::swap(), etc.

template <typename Comparable>
void selection_sort(Comparable arr[], int asize)
{
	// sort all the info in arr (total size: asize) from smallest to largest.
	int nsort = 0; // size of the sorted section.

	while (nsort < asize)
	{
		int spos = findsmallest(arr, nsort, asize - 1);
		swap(arr, spos, nsort); // interchange the 2 values.
		++nsort;
	}
}

template <typename Comparable>
void insertion_sort(Comparable arr[], int asize)
{
	int nsort = 0; // size of the sorted section.

	while (nsort < asize)
	{
		Comparable copy = std::move(arr[nsort]);
		int pos = findpos(arr, copy, nsort);
		// pos is the position for copy.
		// nsort is size of sorted values.

		moveup1(arr, pos, nsort - 1);
		// move data from pos to nsort-1 inclusive.

		arr[pos] = std::move(copy);
		++nsort;
	}
}

// 'a' is an array of 'Items' whose valid elements are between 'start' and 'end', inclusively.
// 'mid' is the position in 'a' in which to divide the array.
template <typename Comparable>
void merge_sort(Comparable a[], int start, int end, int mid)
{

	if (start >= end) // the array is either empty or contains a single element.
		return;		  // sorting problem already solved. Nothing to do.

	// sort the left portion of the array.
	merge_sort(a, start, mid, (start + mid) / 2);

	// sort the right portion of the array
	merge_sort(a, mid + 1, end, (mid + 1 + end) / 2);

	// combined the two sorted array portions in a single sorted array.
	merge(a, start, end, mid);
}

// Returns the position of the smallest Comparable in arr from start to end inclusive
// @pre start <= end
template <typename Comparable>
int findsmallest(const Comparable arr[], int start, int end)
{
	// TODO.
	int min_pos = start;
	for(int i= start+1; i<= end; i++)
	{
		if(arr[i] < arr[min_pos])
		{
			min_pos = i;
		}
	}
	return min_pos;
}

// Swaps the element at position pos1 with the element at position pos2 in arr.
template <typename Comparable>
void swap(Comparable arr[], int pos1, int pos2)
{
	// TODO.
	std::swap(arr[pos1], arr[pos2]);
}

// Returns the position, between 0 and size, in arr to insert the target value in insertion sort.
template <typename Comparable>
int findpos(const Comparable arr[], Comparable target, int size)
{
	// TODO.
	for(int i=0; i<size; i++)
	{
		if(arr[i] > target)
		{
			return i;
		}
		else{
			return -1;
		}
	}
}

// Moves up all data in arr from start to end inclusive one space.
template <typename Comparable>
void moveup1(Comparable arr[], int start, int end)
{
	// TODO.
	for(int i = start; i<= end; i++)
	{
		arr[i+1] = std::move(arr[i]);
	}
}

// Combines two sorted sub-arrays of arr (i.e., the inclusive intervals [left, pivot] and [pivot+1, right])
// to a single sorted array.
template <typename Comparable>
void merge(Comparable arr[], int left, int right, int pivot) {
	// TODO.
	auto const subArrayOne = pivot - left + 1;
    auto const subArrayTwo = right - pivot;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[pivot + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// Template instantiations. Only ints are supported for now. Do not change these but add more instantiations
// for other types if you like.
template void selection_sort<int>(int[], int);
template int findsmallest<int>(const int[], int, int);
template void insertion_sort<int>(int[], int);
template void merge_sort<int>(int[], int, int, int);
