#include <stdio.h>

int main(void)
{
    int n = 2301;                    // n is an integer variable, its value is 2301
    int *p = &n;                     // p is a pointer variable, its value is address of n
    printf("DEREFERENCE: %d\n", *p); // * operator dereference the value of variable point to
    // Output: 2301

    // If n has been changed, so did the value of p
    n = 2001;
    printf("After change n: %d\n", *p);
    // Output: 2001

    // If p has been changed, so did the value of n
    *p = 23;
    printf("After change p: %d\n", n);
    // Output: 23
}
