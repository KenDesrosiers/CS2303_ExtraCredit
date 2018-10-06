#include <stdio.h>
#include <sys/time.h>
#include "sort.h"

/** Prints an array of integers, one per line.
 * @param nums Array to print
 * @param count Number of elements to print
 */

void print_int_array(int nums[], int count) {
  int i; // Loop counter
  for (i = 0; i < count; i++) {
    printf("%d\n", nums[i]); // Print each array element in turn
  }
}

/** Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to sort
 * @param count Number of elements to sort
 */

void sort_descending(int nums[], int count) {
  int round; // How many times left to go through the outer loop.
  int i; // Loop counter for the inner loop
  int inorder; // Used as a boolean (logical). 1 = array is in correct order.
  int temp; // Temporary variable used while swapping array elements

  inorder = 0; // Assume not sorted at the beginning

  // Repeat outer loop, one time less than the size of the array.
  // Terminate early if array is in correct order.
  for(round = count - 1; (round > 0) && (!inorder); round--) {
    inorder = 1; // Assume in correct order, until found otherwise.
    // Repeat inner loop, testing array elements 0 through round
    for (i = 0; i < round; i++) {
      // Compare two adjacent elements of the array
      if (nums[i] < nums[i+1]) {
	// Not in correct relative order, so swap.
	inorder = 0; // At least one pair had to be swapped
	temp = nums[i]; // Swap!
	nums[i] = nums[i+1];
	nums[i+1] = temp;
      }
    }
  }
}



/** Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to sort
 * @param count Number of elements to sort
 */

void sortPointer(int nums[], int count) {
  int round; // How many times left to go through the outer loop.
  int i; // Loop counter for the inner loop
  int inorder; // Used as a boolean (logical). 1 = array is in correct order.
  int temp; // Temporary variable used while swapping array elements
  int* p = nums;
  inorder = 0; // Assume not sorted at the beginning

  // Repeat outer loop, one time less than the size of the array.
  // Terminate early if array is in correct order.
  for(round = count - 1; (round > 0) && (!inorder); round--) {
    inorder = 1; // Assume in correct order, until found otherwise.
    // Repeat inner loop, testing array elements 0 through round
    for (i = 0; i < round; i++) {
      // Compare two adjacent elements of the array
    	int x = i + 1;
      if (*(p+i) < *(p+x)) {
	// Not in correct relative order, so swap.
	inorder = 0; // At least one pair had to be swapped
	temp = *(p+i); // Swap!
	*(p+i) = *(p+x);
	*(p+x) = temp;
      }
    }
  }
}



/** Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to sort
 * @param count Number of elements to sort
 */

void sortIcremPointer(int nums[], int count) {
  int round; // How many times left to go through the outer loop.
  int i; // Loop counter for the inner loop
  int inorder; // Used as a boolean (logical). 1 = array is in correct order.
  int temp; // Temporary variable used while swapping array elements
  inorder = 0; // Assume not sorted at the beginning
  int* p = nums;
  //int* sp = p++;
  //int size = sizeof(nums) / sizeof(int);
  // Repeat outer loop, one time less than the size of the array.
  // Terminate early if array is in correct order.
  //for(round = count - 1; (round > 0) && (!inorder); round--) {
    //inorder = 1; // Assume in correct order, until found otherwise.
    // Repeat inner loop, testing array elements 0 through round
    inorder = 1;
    while (p < &nums[count]) {
    	if (*p < *(p++)) {
    		swap(p, (p++));
    	}
    	p++;
    }
  }
//}

void swap(int *x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/** Prints the contents of a timeval struct.
 * @param t Struct to print.
 */
void print_timeval(struct timeval t) {
  //printf("Not written yet.\n");
	printf("Seconds: %ld\n",t.tv_sec);
	printf("Micro Seconds: %ld\n", t.tv_usec);
}

/** Calculates difference between two timestamps. 
 * Note that this takes structs as parameters and returns a struct;
 * it does not use pointers.
 * @param time1 A time stamp
 * @param time2 another timestamp (assumed same as or later than time 1)
 * @return A timeval struct representing time2 - time1
 */
struct timeval timediff(struct timeval time1, struct timeval time2) {
  struct timeval diff;
  if (time2.tv_usec < time1.tv_usec) {
	  diff.tv_sec = (time2.tv_sec - time1.tv_sec) - 1;
	  diff.tv_usec = (time2.tv_usec - time1.tv_usec) + 999999;
  }
  else {
	  diff.tv_sec = time2.tv_sec - time1.tv_sec;
	  diff.tv_usec = time2.tv_usec - time1.tv_usec;
  }
  return diff;
}
