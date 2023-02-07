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
 */

#ifndef _SORT_H_
#define _SORT_H_

// The sorting functions.
template <typename Comparable>
void selection_sort(Comparable arr[], int asize);

template <typename Comparable>
void insertion_sort(Comparable arr[], int asize);

template <typename Comparable>
void merge_sort(Comparable a[], int start, int end, int mid);

// The sorting "helper" functions.

// Returns the position of the smallest Comparable in arr from start to end inclusive.
// Must work in O(n) time (linear).
template <typename Comparable>
int findsmallest(const Comparable arr[], const int start, const int end);

// Swaps the element at position pos1 with the element at position pos2 in arr.
// Must work in O(1) time (constant).
template <typename Comparable>
void swap(Comparable arr[], const int pos1, const int pos2);

// Returns the position, between 0 and size, in arr to insert the target value in insertion sort.
// Must work in O(n) time (linear).
template <typename Comparable>
int findpos(const Comparable arr[], Comparable target, const int size);

// Moves up all data in arr from start to end inclusive one space.
// Must work in O(n) time (linear).
template <typename Comparable>
void moveup1(Comparable arr[], const int start, const int end);

// Combines two sorted sub-arrays of arr (i.e., the inclusive intervals [left, pivot] and [pivot+1, right]) to a single sorted array.
// The result of this combined, sorted array is stored back into arr to form a single, sorted array, whose valid elements are contained
// in the interval [left, right]. Must work in O(n) time (linear).
template <typename Comparable>
void merge(Comparable arr[], int left, int right, int pivot);

#endif
