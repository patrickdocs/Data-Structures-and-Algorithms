#include <stdio.h>

const int n = 3;
int x[100];
int used[100];

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int check(int v, int k)
{
    for (int i = 1; i <= k-1; i++)
        if (x[i] == v) return 0;

    return 1;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (used[v] == 0) //Marking technique
        {
            x[k] = v;
            used[v] = 1; //v appeared previous, Update the data structure
            if (k == n) {
                solution();
            }
            else Try(k + 1);
            used[v] = 0; //Reset the data structure.

        }

    }
}

int main(void)
{
    for (int i = 1; i <= n; i++)
    {
        used[i] = 0;
    }
    Try(1);
    return 0;
}
