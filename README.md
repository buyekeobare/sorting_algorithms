# 0x1B. C - Sorting algorithms & Big O

## Sorting

Sorting is the process of putting things in order. 
It involves rearranging numbers, words, or any other type of data to make it easier to find whatever you want.  

The primary goal of sorting is to make data easier to search, analyze, and manipulate. 
By organizing elements in a specific order, we can efficiently perform tasks like searching for specific values, finding the minimum or maximum element, identifying duplicates, and more.

Now that we understand what sorting is, lets look at sorting algorithm.

## Sorting Algorithms

Sorting algorithms are important tools in computer science for rearranging elements in a specific order, such as numerical or lexicographical.
They are categorized based on their complexity and efficiency, often measured using Big O notation, which describes the worst-case scenario in terms of time or space complexity.

What is Big 0 Notation?

## Big O Notation

The 'O' in Big O stands for "order of."

Big O Notation is a metric for determining the efficiency of an algorithm. 
It's a way to express the upper bound or worst-case scenario of the time or space complexity of an algorithm as a function of the size of its input.
This simply means, Big 0 Notation helps us understand how the runtime or memory usage of an algorithm grows relative to the size of its input.
Big O Notation is a useful tool for analyzing and comparing the efficiency of algorithms, especially when dealing with large datasets or inputs. 
It allows us to make informed decisions about algorithm selection and optimization.

Big O notation is written as O(f(n)), where:

- O represents the order of the function.
- f(n) represents the function that describes the upper bound of the algorithm's growth rate.

### Common Big O notations include:

- O(1) - Constant time: The algorithm's runtime or space usage is constant, regardless of the size of the input.
- O(log n) - Logarithmic time: The algorithm's runtime or space usage grows logarithmically with the size of the input.
- O(n) - Linear time: The algorithm's runtime or space usage grows linearly with the size of the input.
- O(n log n) - Linearithmic time: The algorithm's runtime or space usage grows in proportion to n times the logarithm of n.
- O(n^2), O(n^3), ... - Polynomial time: The algorithm's runtime or space usage grows quadratically, cubically, etc., with the size of the input.
- O(2^n) - Exponential time: The algorithm's runtime or space usage grows exponentially with the size of the input.

### Types of Sorting Algorithms and their Big O complexities:

1. Bubble Sort:
- Time Complexity: O(n^2) in the worst case
- Space Complexity: O(1)
2. Selection Sort:
- Time Complexity: O(n^2) in the worst case
- Space Complexity: O(1)
3. Insertion Sort:
- Time Complexity: O(n^2) in the worst case
- Space Complexity: O(1)
4. Merge Sort:
- Time Complexity: O(n log n) in the worst case
- Space Complexity: O(n)
5. Quick Sort:
- Time Complexity: O(n^2) in the worst case, but O(n log n) on average
- Space Complexity: O(log n)
6. Heap Sort:
- Time Complexity: O(n log n) in the worst case
- Space Complexity: O(1)
 
And many more.

For our tasks, we will focus on Bubble Sort, Insertion Sort, and Quick Sort. Lets learn more about them.

## Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through a list of elements to be sorted, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the entire list is sorted. The algorithm gets its name from the way smaller elements "bubble" to the top of the list with each iteration.

### Step-by-step explanation of how bubble sort works:

- Start with an unsorted list of elements. For exmaple, we want to sort an array of numbers in ascending order: 8, 6, 10, 4, 2.

Compare the first element with the second elements (8 and 6). 
If the first element is greater than the second element, swap them. In our example, since 6 is smaller than 8, we swap them. Current order: 6, 8, 10, 4, 2.
Move to the next pair of elements (the second and the third i.e 8 and 10) and compare them. 
Again, swap them if they are in the wrong order, but in our case we don't swap them since they are in the correct order. Current order: 6, 8, 10, 4, 2.
Next, we compare 10 and 4. Since 4 is smaller than 10, we swap them. Current order: 6, 8, 4, 10, 2.
Finally, we compare 10 and 2. We swap them because 2 is smaller than 10. Current order: 6, 8, 4, 2, 10.

After the first pass, the largest element (10) is in its correct position at the end of the array.

- We repeat the same process for the remaining unsorted elements. 

Compare 6 and 8. They are already in order, so no swap is needed. Current order: 6, 8, 4, 2, 10.
Compare 8 and 4. We swap them because 4 is smaller than 8. Current order: 6, 4, 8, 2, 10.
Compare 8 and 2. We swap them because 2 is smaller than 8. Current order: 6, 4, 2, 8, 10.

After the second pass, the second largest element (8) is in its correct position.

- We continue the process for the remaining unsorted elements for the third pass.

Compare 6 and 4. We swap them because 4 is smaller than 6. Current order: 4, 6, 2, 8, 10
Compare 6 and 2. We swap them because 2 is smaller than 6. Current order: 4, 2, 6, 8, 10

After the third pass, the third largest element (6) is in its correct position.

- Repeat the process for the fourth pass.

Compare 4 and 2. We swap them because 2 is smaller than 4. Current order: 2, 4, 6, 8, 10.

After the fourth pass, the fourth largest element (4) is in its correct position.

- Repeat the process for the final pass.

No swaps are needed because 2 is already in its correct position.

Since no swaps were made in the last pass, the algorithm knows that the list is fully sorted, and it terminates.

We have learnt in bubble sort sorting algorithm, you repeat the process of comparing and swapping adjacent elements until you reach the end of the list.
The largest element in the unsorted portion of the list will be at the end of the list.


## Insertion Sort

Insertion Sort is a simple comparison-based sorting algorithm that builds the final sorted array one element at a time. It works by iteratively inserting each element into its correct position within the already sorted portion of the array. It repeats this process until the entire list is sorted.

### Step by step explanation of how insertion sort works:

Just like we did in bubble sort sorting algorithm, let's assume we want to sort an array of numbers in ascending order: 8, 6, 10, 4, 2.

- Start with the second element (index 1) of the array and consider it as the "key" to be inserted into the sorted portion of the array.

Our second element or index 1 of the array is (6). 
We compare it with the elements to its left and move it to its correct position among the sorted elements.
Since 6 is smaller than 8, we shift 6 one position to the right. Current order: 6, 8, 10, 4, 2.

- Next, start from the third element (Index 2 of the array). 

Our third element is 10. Insert it into its correct position among the sorted elements (6, 8).
10 is greater than 8, so it remains in its position. Current order: 6, 8, 10, 4, 2.

- Then, start from the fourth element (Index 3 of the array)

We consider the fourth element (4) and insert it into its correct position among the sorted elements (6, 8, 10).
4 is smaller than 10, so we shift 10 one position to the right. 
4 is smaller than 8, so we shift 8 one position to the right. 
Finally, we insert 4 in its correct position. Current order: 4, 6, 8, 10, 2.

- For the fourth pass, we start from the fifth element (Index 4 of the array).
Our fifth element is 2.

Insert it into its correct position among the sorted elements (4, 6, 8, 10).
2 is smaller than 10, so we shift 10 one position to the right.
2 is smaller than 8, so we shift 8 one position to the right.
2 is smaller than 6, so we shift 6 one position to the right. 
Finally, we insert 2 in its correct position. Current order: 2, 4, 6, 8, 10

After the fourth pass, the entire array is sorted.

We have learnt that in insertion sort-sorting algorithm, we compare the key with each element in the sorted portion of the array, moving elements that are greater than the key one position to the right.
The process is repeated until you find the correct position for the key or reach the beginning of the sorted portion, then insert the key into its correct position.

## Quick Sort

QuickSort is a widely used sorting algorithm that follows the divide-and-conquer approach. 
It is known for its efficiency and typically outperforms other sorting algorithms, such as Bubble Sort or Insertion Sort, especially when * dealing with large datasets.

The basic idea behind QuickSort is to select a pivot element from the array and partition the other elements into two sub-arrays based on whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted using the same process until the entire array is sorted.

### Step-by-step explanation of the QuickSort algorithm:

We will continue with our array of numbers from previous explanations. Let's say we want to sort the following array of numbers in ascending order: 8, 6, 10, 4, 2. 

- Choose a pivot: Select an element from the array to serve as the pivot. The choice of the pivot can affect the performance of the algorithm, but a common approach is to select the last element of the array. In our array the last element is 2.

- Partitioning: Rearrange the array in such a way that all elements less than the pivot are moved to the left side of the pivot, and all elements greater than the pivot are moved to the right side. The pivot itself will be in its final sorted position. 

In simpler terms, we partition the array into two sub-arrays: elements less than the pivot and elements greater than or equal to the pivot.
Partition the array around the pivot (2): Current order: 6, 4, 8, 10, 2

Now, all elements less than the pivot (2) are on the left, and all elements greater than or equal to the pivot are on the right.

- Recursion: Recursively apply the above two steps to the sub-arrays on the left and right sides of the pivot. 

This process continues until each sub-array contains only one element, at which point the array is considered sorted.
We do this by recursively apply Quick Sort to the sub-arrays.
For the left sub-array (elements less than the pivot): 6, 4,
Choose a pivot (4).
Partition the sub-array around the pivot (4): 4, 6,
For the right sub-array (elements greater than or equal to the pivot): 8,10,
Choose a pivot (10).
Partition the sub-array around the pivot (10): 8, 10,

- Combining the sub-arrays: As the recursion unwinds, the sub-arrays are combined back to obtain the final sorted array. 
Since both sub-arrays are now sorted, we combine them with the pivot to get the final sorted array: 4, 6, 8, 10, 2.

- Repeat: We repeat the process recursively for each sub-array until the entire array is sorted.
For the left sub-array: 4, 6
For the right sub-array: 8, 10

After the final step, the entire array is sorted.

The time complexity of QuickSort is typically expressed in terms of Big O notation, and in the average case, it has a time complexity of O(n log n), where 'n' is the number of elements in the array.
However, in the worst case, QuickSort's time complexity can degrade to O(n^2), which occurs when the chosen pivot consistently partitions the array into highly imbalanced sub-arrays.
Nevertheless, various optimizations, like choosing a random pivot or implementing the three-way partitioning scheme, can mitigate this issue and make QuickSort perform well in practice.


