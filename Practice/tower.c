#include <stdio.h>

int T = 0;

int HanoiTower(int n, char a, char c, char b)
{
    if (n == 1)
    {
        ++T;
        return 1;
    }
    else
    {
        HanoiTower(n-1, a, b, c);
        HanoiTower(1, a, c, b);
        HanoiTower(n-1, b, c, a);
    }
}

int main(void)
{
    int n;
    printf("n = ");
    scanf("%i", &n);
    printf("%d\n", T);
    return 0;
}
