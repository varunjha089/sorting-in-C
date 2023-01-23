/*
    Here is an example of a C implementation of the quick sort algorithm:

    The quickSort function is the main function that sorts the array. It takes in the array and the 
    left and right indices of the subarray to be sorted. It uses the partition function to divide the 
    array into two parts, one with elements less than the pivot and the other with elements greater than 
    the pivot. The function then recursively calls itself on each half.

    Please note that the above code is just an example, you can use it as a reference to write your own 
    code. Also, The pivot element selection is based on the last element of the array, but you can change 
    it to any other element like random element or middle element, it will change the performance of the algorithm.
*/

void quickSort(int arr[], int low, int high);

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
