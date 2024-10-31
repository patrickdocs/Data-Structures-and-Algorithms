#include <stdio.h>
#include <stdlib.h>

// Two-Dimensional Array is known as a matrix (a table of rows and columns)
// Declare 2D-array: <data_type> <name> [<number_of_rows>][<number_of_columns>];
// Ex: int arr[2][3];
/* - Declare a pointer variable point to 2D-array: <data type>
 * (*<pointer_name>)[<number_of_columns>];
 * - Ex:
 * + int matrix[3][4]
 * + int (*p)[4] = matrix;
 * In this case, pointer p will point to the first row of 2D-array of matrix.
 * ptr + 1 will point to the second row of matrix.
 * Can access an element by: p[i][j] or (*(p + i)[j]) or *(*(p + i) + j)
 */

int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    // Dynamic allocation for 2D array:
    int **twoDimensionalArray = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        twoDimensionalArray[i] = (int *) malloc(cols * sizeof(int));
    }
    // Enter value for 2D array:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &twoDimensionalArray[i][j]);
        }
    }
    // Deallocate the dynamic memory
    for (int i = 0; i < rows; i++)
    {
        free(twoDimensionalArray[i]);
    }
    free(twoDimensionalArray);

    return 0;
}
