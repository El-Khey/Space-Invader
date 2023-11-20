#include "../../include/utils/utils.h"

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a > b ? b : a; }

char *convert_int_to_string(int number)
{
    char *str = (char *)malloc(10 * sizeof(char));
    sprintf(str, "%d", number);

    return str;
}