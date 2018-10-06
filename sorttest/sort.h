#ifndef SORT_H
#define SORT_H

// Function prototypes:
void timesort (int a[], int count, int which);
void print_int_array(int nums[], int count);
void sort_descending(int nums[], int count);
void print_timeval(struct timeval t);
struct timeval timediff(struct timeval time1, struct timeval time2);
void sortPointer(int nums[], int count);
void sortIcremPointer(int nums[], int count);
void swap(int *x, int* y);
#endif
