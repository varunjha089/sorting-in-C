#include <stdio.h>
#include "selection_sort.c"
// void selection_sort(int arr[], int n);

int main(){
    int arr[7] = {6, 4, 8, 19, 18, 17, 11};
    
    selection_sort(arr, 7);
    for(int i = 0; i<7; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return(0);
}
