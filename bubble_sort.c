/*
    Here is an example of bubble sort implemented in C:

    This implementation takes an array of integers, arr, and its length, n, as input. .The outer loop runs 
    from 0 to n-2 and the inner loop runs from 0 to n-i-2. The algorithm repeatedly swaps adjacent elements 
    if they are in the wrong order. The outer loop ensures that the largest element "bubbles" to the end of 
    the array in each iteration.
*/
void swap(int *, int *);

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
