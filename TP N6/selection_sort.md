# Selection Sort

## Abstract

Selection Sort is a simple and efficient sorting algortim that works by repeatdly selecting the smallest (or largest) element from the unsorted portion of the list and moving it to the sorted portion.

## Algorithm

For the example we gonna use the following list:

```c
int unsortedVector = [64, 25, 12, 22, 11];
```

The first step is to find the smallest element in the list, going through it all, and then swap it with the first element of the array.

In this case we gonna swap 11 with 64.

```c
int unsortedVector = [11, 25, 12, 22, 64];
```

Now we repeat this mechanism 3 more times.

```c
int unsortedVector = [11, 12, 25, 22, 64];
```

One more time

```c
int unsortedVector = [11, 12, 22, 25, 64];
```

In the last step, we see that the 4rd element is lower than tha last one. So it stays the same.

## Time Complexity

Time complexity is O(N^2), because it is based in two nested loops.

- The first loop to select the smallest element of the list (O(N))
- The second one that element with every other Array element = O(N)

Overall complexity = O(N) * O(N) = O(N*N) = O(N^2)

## Auxiliary Space

O(1): The only extra memory used are the temporal variables while swapping two values of the array.

The selection sort never makes more than O(N) swaps and can be useful when memory writing is costly.

## Advantages

- Simple and easy to understand
- Works well with small datasets

## Disdvantages

- Selection sort has a time complexity of O(N^2) in the worst and average case.
- Does not work well with large data sets
- Does not preseve the relative order of items with equal keys so it is not stable.

## Implementation

```c
#include <stdio.h>
#include <stbool.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//An optimized version of Selection sort
void selectionSort(int array[], int n){
    int min_index;

    // One by one move boundary of unsorted subarray
    for(int i = 0; i < n-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;

        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}


```