#include "../../../include/gui/label/temporary_message.h"

TemporaryMessage construct_temporary_message(Text text, int duration)
{
    TemporaryMessage message;

    message.text = text;
    message.duration = duration;
    message.start_time = MLV_get_time();

    return message;
}

void reset_temporary_message(TemporaryMessage *message)
{
    message->start_time = MLV_get_time();
}

void temporary_message_set_duration(TemporaryMessage *message, int duration)
{
    message->duration = duration;
}

void temporary_message_set_text(TemporaryMessage *message, Text text)
{
    message->text = text;
}

void draw_temporary_message(TemporaryMessage message)
{
    if (MLV_get_time() - message.start_time > message.duration)
    {
        return;
    }

    draw_text(message.text);
}

void free_temporary_message(TemporaryMessage *message)
{
    free_text(&message->text);
}