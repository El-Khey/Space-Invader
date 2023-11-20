#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Returns the maximum of two integers
 *
 * @param a The first integer
 * @param b The second integer
 * @return int
 */
int max(int a, int b);

/**
 * @brief Returns the minimum of two integers
 *
 * @param a The first integer
 * @param b The second integer
 * @return int
 */
int min(int a, int b);

/**
 * @brief Convert an integer to a string
 *
 * @param number The number to convert
 * @return char*
 */
char *convert_int_to_string(int number);

#endif