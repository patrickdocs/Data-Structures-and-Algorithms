#include <stdio.h>

int main()
{
    // An array is a set of same of data type of variable
    int a[5];                // Declare an array has 5 elements which are integer type
    a[0] = 1;                // Pass 1 to the first element
    a[1] = 2;                // Pass 2 to the second element
    printf("%d\n", a[a[0]]); // a[a[0]] = a[1] = 2

    // Besides, array can be declared as following:
    int b[] = {1, 2, 3, 4, 5};
    printf("%d\n", b[2]); // Print the third element of array

    // An array is also same as a pointer point to the first element of array
    int *p = a;
    int *q = &a[0];

    printf("%d\n", a[0]);
    printf("%d\n", *p);
    printf("%d\n", *q); // Same output

    // a is address of the first array's element
    // *a is as same as a[0]
    *a = 10;              // Pass 10 for the first element of array
    printf("%d\n", a[0]); // Output: 10

    // a+1 is address of the second array's element
    // a+1 is as same as &a[1]
    *(a + 1) = 20;        // Pass 20 for the second element of array
    printf("%d\n", a[1]); // Output: 20
}
