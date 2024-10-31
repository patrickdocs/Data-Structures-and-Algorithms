#include <stdio.h>

/* Problem: Find the number n_th in Fibonacci sequence.
 | - Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 | - F(0) = 0, F(1) = 1, F(n) = F(n - 1) + F(n - 2) for n >= 2.
 */

/* Parameter:
 | - Input: n.
 | - Output: n_th Fibonacci number.
 */

/* Version 1: RECURSION: O(1.618^n) | O(1)
 | - Recursion relation:
 |    + Base case:      F(n) = n, if n = 0 or n = 1.
 |    + Recursion case: F(n) = F(n - 1) + F(n - 2), for n > 1.
 | - According to Master Theorem: T(n) = T(n - 1) + T(n - 2) + O(1) -> T(n) = O(1.618^n).
 */

int fibonacciVer1(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacciVer1(n - 1) + fibonacciVer1(n - 2);
}

/* Version 2: -> MEMOIZATION Approach: O(n) time  | O(n) space
 | - Using an array f[] to store the result of previously calculated Fibonacci numbers
 | - Formula: F(n) = F(n - 1) + F(n - 2).
 */

int fibonacciVer2(int n) {
    int f[n+1];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

/* Version 3: -> SPACE OPTIMIZED Approach: O(n) time  | O(1) space
 | - we can store two previous numbers only in the variables.
 */

int fibonacciVer3(int n) {
    int a = 0, b = 1, c;
    if (n == 0) {
        return a;
    }
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacciVer1(n));
    printf("%d\n", fibonacciVer2(n));
    printf("%d\n", fibonacciVer3(n));
    return 0;
}
 //n = 45 is the limitation
