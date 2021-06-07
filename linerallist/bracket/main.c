#include <stdio.h>

#include "stack.h"

int main()
{
    char *str = "({[[]]}){}";

    match(str);

    return 0;
}