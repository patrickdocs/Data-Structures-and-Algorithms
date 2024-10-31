#include <stdio.h>
#include <stdlib.h>

/* Problem: Calculate binomial Coeficient C(n, k) for n, k is not negative integers.
 * - Formula: C(n, k) = n! / (k! * (n - k)!).
 * - Characteristic: C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
 */

/* Parameter:
 | - Input: n, k.
 | - Output: result of C(n, k).
 */

/* Version 1: -> RECURSION: O(2^n) time | O(1) space
 | - Formula: C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
 | - If k = 0 or k = n, return 1.
 | - Time complexity: O(2^n).
 */

int binomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

/* Version 2: -> MEMOIZATION approach(Dynamic Programming): O(n*k) time | O(n*k) space
 | - Formula: C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
 | - If k = 0 or k = n, return 1.
 | - Using matrix C[n+1][k+1] to store value of C(n, k)
 | - Time complexity: O(n*k).
 */
int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}

int binomialDP(int n, int k) {
    int C[k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = min(i, k); j >= 0; j--) {
            if (j == 0 || j == i ) {
                C[j] = 1;
            }
            else {
                C[j] = C[j - 1] + C[j];
            }
        }
    }
    return C[k];
}


int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    if (k < 0 || n < 0 || k > n){
        return 0;
    }
    printf("%d\n", binomial(n, k));
    printf("%d\n", binomialDP(n, k));
    return 0;
}
