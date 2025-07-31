#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Declare your parsing-related functions
int     *parse_wq(char *str);
void    free_split(char **split);
int     arg_count(char *str);

// Helper to print the result array
void print_array(int *arr, int count)
{
    if (!arr)
    {
        printf("parse_wq returned NULL\n");
        return;
    }
    printf("Parsed result: ");
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    char *tests[] = {
        "1 2 3 4 5",                      // ✅ valid
        "42",                            // ✅ single value
        "2147483647 -2147483648 0",      // ✅ INT_MAX, INT_MIN
        "    123   456  ",               // ✅ extra spaces
        "",                              // ❌ empty string
        "    ",                          // ❌ only spaces
        "1 2 3 3",                       // ❌ duplicate
        "12a 34",                        // ❌ invalid char
        "+123 -456",                    // ✅ signed numbers
        "--1 2",                         // ❌ invalid double sign
        "2147483648",                   // ❌ > INT_MAX
        "-2147483649",                  // ❌ < INT_MIN
        "00001 0001",                   // ❌ duplicate after conversion
        NULL
    };

    for (int i = 0; tests[i]; i++)
    {
        printf("Test %d: \"%s\"\n", i + 1, tests[i]);
        int *res = parse_wq(tests[i]);
        if (res)
        {
            int count = arg_count(tests[i]);
            print_array(res, count);
            free(res);
        }
        else
        {
            printf("Invalid input or error detected.\n");
        }
        printf("--------\n");
    }
    return 0;
}