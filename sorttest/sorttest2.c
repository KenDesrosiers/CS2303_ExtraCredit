#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>


/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {
	srand(time(0));
  int *arr;
  int count = atoi(argv[2]);
  int whichOne = atoi(argv[3]);

  arr = (int*) calloc(count, sizeof(int));
  if (arr == NULL) {
	  fprintf(stderr, "Unable to allocate enough memory to hold the numbers.\n");
  }

  for (int i = 0; i < count; i++) {
	  arr[i] = rand();
  }
  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(arr, count, whichOne);

  return 0; // Indicate success!
}
