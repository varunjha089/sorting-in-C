# Sorting in C

| Name | Description | Time Complexity | Link |
|--- |--- |--- |--- |
| Quick Sort | Quick sort implementation | O(n*logn) | [Quick Sort](quick_sort.c) |


## Matrix Chain Multiplication

Matrix chain multiplication is a way to multiply a sequence of matrices in an efficient manner. The basic idea is to break down the multiplication of a chain of matrices into smaller multiplications, which can then be combined to give the final result. The order in which the matrices are multiplied can be important, as it can affect the number of computations required. A common technique to determine the optimal order is the dynamic programming approach called matrix chain multiplication.

Here is an algorithm for matrix chain multiplication using dynamic programming:

1. Let n be the number of matrices in the chain.
2. Create a table, m[n][n], to store the minimum number of multiplications required to multiply the chain of matrices from i to j.
3. Initialize the diagonal of the table with 0, as the minimum number of multiplications required to multiply a single matrix is 0.
4. For the remaining positions in the table, use the following formula to compute the value:
    - `m[i][j] = min(m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]) for i <= k < j`
5. where p[i] is the number of columns in the matrix i. The minimum number of multiplications required to multiply the entire chain is stored in m[1][n].

Note that the above algorithm uses a bottom-up approach, where we start by computing the minimum number of multiplications required for the subproblems of smaller size and use that information to compute the minimum number of multiplications required for larger subproblems.

Also, it is important to note that this algorithm assumes that the matrices can be multiplied in the given order, i.e the number of columns of the matrix i is equal to the number of rows of the matrix i+1.

```c
#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ", matrixChainOrder(arr, size));
    return 0;
}
```

In this implementation, the function matrixChainOrder() takes an array p[] that represents the chain of matrices, with p[i-1] being the number of rows in matrix i, and an integer n that represents the number of matrices in the chain.

It initializes a 2D array `m[n][n]` to store the minimum number of multiplications required to multiply the chain of matrices from i to j. It uses a nested loop to fill the array `m[n][n]` using the dynamic programming approach.

The minimum number of multiplications required to multiply the entire chain is returned from the function and printed in the main() function.

It is important to notice that this is a simplistic example and it should be used for demonstration purposes only, it is not optimal or efficient in any way.


Certainly! The above C code is an implementation of the matrix chain multiplication algorithm using dynamic programming. The algorithm takes an array `p[]` of dimensions of matrices and an integer `n` that represents the number of matrices in the chain.

Here is a breakdown of the main steps in the code:
1. The function `matrixChainOrder()` starts by initializing the diagonal of the table `m[n][n]` with 0, as the minimum number of multiplications required to multiply a single matrix is 0.
