#include <stdio.h>

// In C language, there is 2 way to pass argumnet/parameter for function:
/* - Pass by value: pass VALUE to variable of function, C only passes the copies of
 *  variables and function modified the copies, but the originals haven't been change.
 * - Pass by reference: pass ADDRESS to variable of function,
 *   this allows the function to change the value outside the function.
 */

// Example for Pass by Value
int addByValue(int a)
{
    return (a += 10);
}

int addByReference(int *a) // a is a pointer variable point to integer variable
{
    return (*a += 5);
}

int main(void)
{
    int a = 3;
    addByValue(a);
    printf("a = %d\n", a); // Output: a = 3, no change

    addByReference(&a);
    printf("a = %d\n", a); // Output: a = 8, has been changed

    return 0;
}
