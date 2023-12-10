#ifndef BUTTON_H
#define BUTTON_H

#include "../../game/manager/event_manager/mouse_manager/mouse_manager.h"

#include "../../utils/dimension/dimension.h"
#include "../../utils/animation/animation.h"
#include "../../utils/position/position.h"
#include "../../utils/image/image.h"
#include "../../utils/text/text.h"
#include "../../gui/shape/shape.h"

typedef struct
{
    Image image;
    Animation animation;

    Position position;
    Dimension dimension;

    Text text;

    MLV_Color background;
    MLV_Color foreground;
} Button;

typedef Button GUI_Object;

/**
 * @brief Construct a new Button object with an image
 *
 * @param image The image of the button
 * @param position The position of the button
 * @param dimension The dimension of the button
 * @return Button
 */
Button construct_button_with_image(Image image, Position position, Dimension dimension);

/**
 * @brief Construct a new Button object with an animation
 *
 * @param animation The animation of the button
 * @param position The position of the button
 * @param dimension The dimension of the button
 * @return Button
 */
Button construct_button_with_animation(Animation animation, Position position, Dimension dimension);

/**
 * @brief Construct a new Button object with a text
 *
 * @param text The text of the button
 * @param position The position of the button
 * @param dimension The dimension of the button
 * @return Button
 */
Button construct_button_with_text(char *text, Position position, Dimension dimension, MLV_Color foreground, MLV_Color background);

/**
 * @brief Set the position of the button
 *
 * @param button The button to set the position of
 * @param position The position to set the button position to
 */
void set_button_position(Button *button, Position position);

/**
 * @brief Set the dimension of the button
 *
 * @param button The button to set the dimension of
 * @param dimension The dimension to set the button dimension to
 */
void set_button_dimension(Button *button, Dimension dimension);

/**
 * @brief Draw the button with a hover effect
 *
 * @param button The button to draw
 * @param mouse_position The mouse position
 * @param foreground The foreground color
 * @param background The background color
 */
void draw_filled_button_with_hover_effect(Button button, Position mouse_position, MLV_Color border_color, MLV_Color background);

/**
 * @brief Draw the hovered button
 *
 * @param button The button to draw
 * @param mouse_position The mouse position
 * @param border_color The border color
 * @param background The background color
 */
void draw_hovered_button(Button button, Position mouse_position, MLV_Color border_color, MLV_Color background);
/**
 * @brief Check if the button is hovered
 *
 * @param button The button to check if it is hovered
 * @param p The position to check if the button is hovered
 * @return int
 */
int is_button_hovered(Button button, Position p);

/**
 * @brief Check if the button is clicked
 *
 * @param button The button to check if it is clicked
 * @param mouse_manager The mouse manager to check if the button is clicked
 * @return int
 */
int is_button_clicked(Button button, MouseManager mouse_manager);

/**
 * @brief Draw the button
 *
 * @param button The button to draw
 */
void draw_button_image(Button button);

/**
 * @brief Draw the button text
 *
 * @param button The button to draw the text of
 */
void draw_button_text(Button button);

/**
 * @brief Draw the button animation
 *
 * @param button The button to draw the animation of
 */
void draw_button_animation(Button button);

/**
 * @brief Free the button image
 *
 * @param button The button to free the image of
 */
void free_button_image(Button *button);

/**
 * @brief Free the button text
 *
 * @param button The button to free the text of
 */
void free_button_text(Button *button);

/**
 * @brief Free the button animation
 *
 * @param button The button to free the animation of
 */
void free_button_animation(Button *button);

#endif