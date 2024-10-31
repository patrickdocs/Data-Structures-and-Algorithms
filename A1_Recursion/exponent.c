#include <stdio.h>

// Problem: Calculate a^n for n >= 0, n is integer.

/* Parameter:
 | - Input: a, n.
 | - Output: the result of a^n.
 */

/* Algorithm: -> RECURSION: O(log(n)) time | O(1) space
 | - Formula: a^n = a^(n/2) * a^(n/2) if n is even và a^n = a^(n/2) * a^(n/2) * a if n is odd.
 | - If n = 0, return 1.
 | - According to Master Theorem: T(n) = T(n/2) + O(1) -> T(n) = O(log(n)).
 */

// Recursion fucntion to calculate a^n -> Time: O(log_2(n)) or O(log(n))

long power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    long temp = power(a, n /2);
    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return a * temp * temp;
    }
}

int main(void)
{
    int a, n;
    scanf("%d%d", &a, &n);
    printf("%ld\n", power(a, n));
    return 0;
}
