#ifndef TEMPORARY_MESSAGE_H
#define TEMPORARY_MESSAGE_H

#include "../../utils/text/text.h"

typedef struct
{
    Text text;

    int start_time;
    int duration;
} TemporaryMessage;

/**
 * @brief Construct a new Temporary Message object
 *
 * @param text The text to be displayed
 * @param duration The duration of the message in milliseconds
 * @return TemporaryMessage
 */
TemporaryMessage construct_temporary_message(Text text, int duration);

/**
 * @brief Reset the start time of the message
 *
 * @param message The message to be modified
 */
void reset_temporary_message(TemporaryMessage *message);

/**
 * @brief Set the duration of the message
 *
 * @param message The message to be modified
 * @param duration The new duration of the message
 */
void temporary_message_set_duration(TemporaryMessage *message, int duration);

/**
 * @brief Set the text of the message
 *
 * @param message The message to be modified
 * @param text The new text of the message
 */
void temporary_message_set_text(TemporaryMessage *message, Text text);

/**
 * @brief Draw the message on the screen
 *
 * @param message The message to be drawn
 */
void draw_temporary_message(TemporaryMessage message);

/**
 * @brief
 *
 * @param message
 */
void free_temporary_message(TemporaryMessage *message);

#endif