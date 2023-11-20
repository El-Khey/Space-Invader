#ifndef Position_H
#define Position_H

#include <stdio.h>

typedef struct
{
    int x, y;
} Position;

/**
 * @brief Construct a new Position object with the given coordinates
 *
 * @param x The x coordinate
 * @param y The y coordinate
 * @return Position
 */
Position construct_position(int x, int y);

/**
 * @brief Get the x coordinate of the given position
 *
 * @param p The position
 * @return int
 */
int get_x(Position p);

/**
 * @brief Get the y coordinate of the given position
 *
 * @param p The position
 * @return int
 */
int get_y(Position p);

/**
 * @brief Set the x coordinate of the given position
 *
 * @param p The position
 * @param x The new x coordinate
 */
void set_x(Position *p, int x);

/**
 * @brief Set the y coordinate of the given position
 *
 * @param p The position
 * @param y The new y coordinate
 */
void set_y(Position *p, int y);

/**
 * @brief Move the given position by the given amount in the x direction
 *
 * @param p The position
 * @param dx The amount to move in the x direction
 */
void move_y(Position *p, int dy);

/**
 * @brief Move the given position by the given amount in the y direction
 *
 * @param p The position
 * @param dx The amount to move in the y direction
 */
void move_x(Position *p, int dx);

/**
 * @brief Move the given position by the given amount
 *
 * @param p The position
 * @param dx The amount to move in the x direction
 * @param dy The amount to move in the y direction
 */
void move_position(Position *p, int dx, int dy);

/**
 * @brief Print the given position on the screen
 * The position is printed in the following format: Position: (x, y)
 * Should be used for debugging purposes only
 *
 * @param p The position to print
 */
void print_position(Position p);

#endif