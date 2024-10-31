#include <stdio.h>
#include <string.h> //Library helps process string

int main() {
    // A string is a character-type array which ends by character '\0'
    char s[100]; //Declare an array s which has 100 characters
    scanf("%s", s); //Get input
    printf("%s\n", s);

    // The length of a string:
    int length = strlen(s);
    printf("%d\n", length);

    // Combine strings:
    char s1[100], s2[100];
    scanf("%s%s", s1, s2);
    strcat(s1, s2); //This function uses to concatenate s2 into s2, result stores to s1
    printf("%s\n", s1);

}

