#include <stdio.h>

// Problem: Find the greatest common divisor of two positive integers a and b.

/* Parameter:
 | - Input: a, b.
 | - Output: The greatest common divisor of a and b.
 */

/* Version 1: -> RECURSION: O(log(min(a, b))) | O(log(min(a, b))) space
 | - Formula: gcd(a, b) = gcd(b, a % b).
 | - If b = 0, return a.
 | - Limitation: if inputs are large, may be limited by stack size
 */

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}


/* Version 2: -> ITERATION: O(log(min(a, b))) | O(1) space
 | - Formula: Continuously update a and b: a = b, b = a % b.
 | - Process: Repeat until b becomes 0, then return a as the GCD.
 | - Advantage: No recursion, so it avoids stack overflow for large inputs.
 */

int gcdVer2(int a, int b) { // more commonly used in reality
    int temp;
    while (b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a,b));
    printf("%d\n", gcdVer2(a,b));
    return 0;
}
