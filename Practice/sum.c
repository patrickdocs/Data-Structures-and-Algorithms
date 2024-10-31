#include <stdio.h>

int sum(int A[], int size)
{
    int sum = A[0];
    for (int i = 1; i < size; i++)
    {
        sum += A[i];
    }
    return sum;
}

int main(void)
{
    int n;
    int A[20];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("%d\n", sum(A, n));
    return 0;
}
