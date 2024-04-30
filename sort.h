#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* MAIN FUNCTIONS*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* HELPER FUNCTIONS*/
void swaps_int(int *a, int *b);
void swaps_node(listint_t **list, listint_t *node);
int partition(int *array, size_t size, int l, int h);
void quicksort_lomuto(int *array, size_t size, int l, int h);
void sub_merge_sort(int *sub, int *buffer, size_t l, size_t mid, size_t h);
void call_merge_sort(int *sub, int *buffer, size_t l, size_t h);
int get_max_array(int *array, int size);
void lsd_radix_sort(int *array, size_t size, int exp, int *copy);
void heap_sort_helper(int *array, int subarray, int super_node, size_t size);
size_t partition_sort_hoare(int *array, ssize_t l, ssize_t h, size_t size);
void partition_sort(int *array, ssize_t l, ssize_t h, size_t size);
int partitions(int *array, size_t size, int up, int down);

/* PROJECT FUNCTIONS*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
