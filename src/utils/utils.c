#include "../../include/utils/utils.h"

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a > b ? b : a; }

int is_position_with_dimension_inside_rect(Position pos, Dimension dim, Position rect_pos, Dimension rect_dim)
{
    return pos.x >= rect_pos.x && pos.x + dim.width <= rect_pos.x + rect_dim.width && pos.y >= rect_pos.y && pos.y + dim.height <= rect_pos.y + rect_dim.height;
}

char *concat(char *s1, char *s2)
{
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

char *convert_int_to_string(int number)
{
    char *str = (char *)malloc(10 * sizeof(char));
    sprintf(str, "%d", number);

    return str;
}

char *convert_timestamp(time_t timestamp)
{
    struct tm *timeinfo;
    char *formatted_time = malloc(20 * sizeof(char));
    timeinfo = localtime(&timestamp);
    strftime(formatted_time, 20, "%d-%m-%y", timeinfo);
    return formatted_time;
}