#include <stdio.h>


int findMax(int A[], int size)
{
    int max = A[0];
    for (int i = 1; i < size; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}

int main(void)
{
    int n;
    int A[20];

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    printf("%d\n", findMax(A, n));
    return 0;
}

