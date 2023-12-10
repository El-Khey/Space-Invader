#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>

#include "./position/position.h"
#include "./dimension/dimension.h"

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
 * @brief
 *
 * @param position
 * @param rect_dimension
 * @param rect_position
 * @return int
 */
int is_position_with_dimension_inside_rect(Position pos, Dimension dim, Position rect_pos, Dimension rect_dim);

/**
 * @brief Convert an integer to a string
 *
 * @param number The number to convert
 * @return char*
 */
char *convert_int_to_string(int number);

/**
 * @brief Concatenate two strings
 *
 * @param s1 The first string
 * @param s2 The second string
 * @return char*
 */
char *concat(char *s1, char *s2);

/**
 * @brief Convert a timestamp to a string
 *
 * @param timestamp The timestamp
 * @return char*
 */
char *convert_timestamp(time_t timestamp);

#endif