#include <stdio.h>
#include "selection_sort.c"
#include "bubble_sort.c"
#include "quick_sort.c"
// void selection_sort(int arr[], int n);

int main(){
    int arr[7] = {6, 4, 8, 19, 18, 17, 11};
    int n;
    
    printf("Please select one sorting algo\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Quick Sort\n");

    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("You have selected Selection Sort\n");
        selection_sort(arr, 7);
        break;
    
    case 2:
        printf("You have selected Bubble Sort\n");
        bubbleSort(arr, 7);
        break;

    case 3:
        printf("You have selected Quick Sort\n");
        quickSort(arr, 0, 6);
        break;

    default:
        break;
    }

    for(int i = 0; i<7; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return(0);
}
