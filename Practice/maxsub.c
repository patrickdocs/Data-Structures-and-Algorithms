#include <stdio.h>
#include <math.h>

int n;
int a[100];

int maxleft(int l, int r)
{
    int s = 0;
    int max = -10e6;
    for (int i = l; i >= r; i--)
    {
        s += a[i];
        if (s > max)
        {
            max = s;
        }
    }
    return max;
}

int maxright(int l, int r)
{
    int s = 0;
    int max = -10e6;
    for (int i = l; i <= r; i++)
    {
        s += a[i];
        if (s > max)
        {
            max = s;
        }
    }
    return max;
}
int DC(int l, int r)
{
    if (l == r) {
        return a[l];
    }
    int mid = (l + r) / 2;
    int s1 = DC(l, mid);
    int s2 = DC(mid + 1, r);
    int s3 = maxleft(l, mid) + maxright(mid+1, r);

    return fmax(fmax(s1,s2), s3);
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int maxsum = DC(0, n-1);
    printf("%d\n", maxsum);

}

