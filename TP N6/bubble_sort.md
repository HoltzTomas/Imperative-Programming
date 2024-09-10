# Bubble Sort

## Abstract

Bubble sort is the simplest sorting algoritm.

It works by repeatdly swapping tha adjacent elements if they are in the wrong order.

The algoritm is not suitable for large data sets as its average and worst case time complexity is high.

### Example

```c
int unsortedArray[] = {6, 0, 3, 5};
```

Traverse from left and compare adjacent elements and the higher one is placed at right side. 

So at the end of the first step the largest element will be at the rightmost position.

```c
int unsortedArray[] = {0, 3, 5, 6};
```

We can see tha it is already sorted. But this not gonna happen in all cases. We have to repeat the mechanism, find the second largest element and move it to the its position.

The we do the seam with the 3rd largest and we finished, the amount of steps is always N-1. Being N the amount of elements in the array.

The amount of comparisons will be n*(n-1)/2

### Time Complexity O(N^2)

### Auxiliary Space O(1)

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

//An optimized version of Bubble sort
void bubbleSort(int array[], int n){
    bool swapped;
    
    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            swap(&arr[j], &arr[j + 1]);
            swapped = true;
        }

        // If no two elements were swapped by inner loop, then break
        if(!swapped){
            break;
        }
    }
}


```