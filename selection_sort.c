/*
    Selection sort is a simple sorting algorithm that repeatedly selects the smallest element from an unsorted list 
    and places it at the beginning of the sorted list. Here is an example implementation of selection sort in C:

    The function takes in an array arr and its size n as input. It iterates through the array, and in each iteration, 
    finds the index of the smallest element from the unsorted portion of the array. Then, it swaps the element at that 
    index with the first element of the unsorted portion, effectively moving the smallest element to the beginning of 
    the sorted portion of the array. This process is repeated until the entire array is sorted.
    
    It is important to keep in mind that selection sort is not an efficient sorting algorithm and has a time complexity 
    of O(n^2) which makes it inefficient for large data sets.
*/

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
