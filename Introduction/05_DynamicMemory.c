#include <stdio.h>
#include <stdlib.h>

// When should use dynamic memory?
/* - When you can not figure out the need to store of a program before it runs
 * Ex: don't know the size of data that program will process,
 * or dont know the processing object
 */

//Compare to static memory, dynamic memory seems to be less efficient because:
/* - The cost of managing memory
 * - Must deallocate memory when finish using it.
 * if not, can cause memory leak.
 */

int main() {
    struct Point {
        int x, y;
    };

    //Allocate memory for variable type struct Point
    struct Point *p = (struct Point *)malloc(sizeof(struct Point));
    p->x = 10;
    p->y = 20;

    printf("%d %d\n", p->x, p->y);
    free(p); // Deallocate memory which allocated for p
}
