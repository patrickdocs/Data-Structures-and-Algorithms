#include <stdio.h>

const int n = 5;

int findMin(int A[], int size)
{
    int min = A[0];
    for (int i = 1; i < size; i++)
    {
        if (min > A[i])
        {
            min = A[i];
        }
    }
    return min;
}

int main(void)
{
    int A[] = {1, 3, 5, -8, 9};
    printf("%d\n", findMin(A, n));
}

