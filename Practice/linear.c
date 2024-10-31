#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // An array of strings
    string names[] = {"Quan", "Hai", "Kiet"};
    string address[] = {"37 - Nghe An", "29 - Ha Noi", "98 - Bac Giang"};
    //Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", address[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
