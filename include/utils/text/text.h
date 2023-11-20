#ifndef TEXT_H
#define TEXT_H

#include "../position/position.h"
#include "../dimension/dimension.h"
#include "../utils.h"

#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *text;

    Dimension dimension;
    Position position;

    MLV_Color color;

    MLV_Font *font;
    int font_size;

    char *font_path;
} Text;

/**
 * @brief Construct a Text object
 *
 * @param text The text to construct
 * @param position The position of the text
 * @param font_path The path of the font
 * @param font_size The size of the font
 * @param color The color of the text
 * @return Text
 */
Text construct_text(char *text, Position position, char *font_path, int font_size, MLV_Color color);

/**
 * @brief Set the text content
 *
 * @param text The text to set the content
 * @param content The content to set
 */
void set_text_content(Text *text, char *content);

/**
 * @brief Set the text position
 *
 * @param text The text to set the position
 * @param position The position to set
 */
void set_text_position(Text *text, Position position);

/**
 * @brief Get the text width
 *
 * @param text The text to get the width
 * @return int
 */
int get_text_width(Text text);

/**
 * @brief Get the text height
 *
 * @param text The text to get the height
 * @return int
 */
int get_text_height(Text text);

/**
 * @brief Draw a text
 *
 * @param text The text to draw
 */
void draw_text(Text text);

/**
 * @brief Draw a text with a shadow
 *
 * @param text The text to draw
 * @param shadow_offset The offset of the shadow
 */
void draw_text_with_shadow(Text text, int shadow_offset);

/**
 * @brief Format milliseconds to a string
 *
 * @param buffer The buffer to store the formatted string
 * @param milliseconds The milliseconds to format
 */
void format_milliseconds(char *buffer, int milliseconds);

/**
 * @brief Destroy a text
 *
 * @param text The text to destroy
 */
void free_text(Text *text);

#endif /** TEXT_H */