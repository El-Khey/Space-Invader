#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>

#include "./position/position.h"
#include "./dimension/dimension.h"

/**
 * @brief Retourne le maximum de deux entiers
 *
 * @param a Le premier entier
 * @param b Le deuxième entier
 * @return int
 */
int max(int a, int b);

/**
 * @brief Retourne le minimum de deux entiers
 *
 * @param a Le premier entier
 * @param b Le deuxième entier
 * @return int
 */
int min(int a, int b);

/**
 * @brief Vérifie si une position avec une dimension est à l'intérieur d'un rectangle
 *
 * @param pos La position
 * @param dim La dimension
 * @param rect_pos La position du rectangle
 * @param rect_dim La dimension du rectangle
 * @return int
 */
int is_position_with_dimension_inside_rect(Position pos, Dimension dim, Position rect_pos, Dimension rect_dim);

/**
 * @brief Convertit un entier en une chaîne de caractères
 *
 * @param number Le nombre à convertir
 * @return char*
 */
char *convert_int_to_string(int number);

/**
 * @brief Concatène deux chaînes de caractères
 *
 * @param s1 La première chaîne de caractères
 * @param s2 La deuxième chaîne de caractères
 * @return char*
 */
char *concat(char *s1, char *s2);

/**
 * @brief Convertit un horodatage en une chaîne de caractères
 *
 * @param timestamp L'horodatage
 * @return char*
 */
char *convert_timestamp(time_t timestamp);

#endif