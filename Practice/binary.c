#include <stdio.h>

void generateBinaryStrings(int n, char A[], int i)
{
    // Base case: if the current index i is equal to n, print the binary string
    if (i == n) {
        A[i] = '\0';  // Null-terminate the string for printing
        printf("%s\n", A);
        return;
    }

    // Assign '0' at index i and recur for the rest of the positions
    A[i] = '0';
    generateBinaryStrings(n, A, i + 1);

    // Assign '1' at index i and recur for the rest of the positions
    A[i] = '1';
    generateBinaryStrings(n, A, i + 1);
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    char A[n + 1];  // Create an array to hold the binary string

    // Generate and print all binary strings of length n
    generateBinaryStrings(n, A, 0);

    return 0;
}
