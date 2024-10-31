#include <stdio.h>

int f(int n, int x);

int main(void)
{
    int n, x;
    printf("n = ");
    scanf("%i", &n);
    printf("x = ");
    scanf("%i", &x);
    printf("f(%d, %d) = %d\n", n, x, f(n, x));
}

int f(int n, int x)
{
    if (n <= 0) return x;
    else
    {
        return f(n-1, x-1) + f (n-1, x+1) + f(n-2, x);
    }
}
