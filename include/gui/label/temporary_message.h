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
 * @brief Construit un nouvel objet de message temporaire.
 *
 * @param text Le texte à afficher.
 * @param duration La durée du message en millisecondes.
 * @return TemporaryMessage
 */
TemporaryMessage construct_temporary_message(Text text, int duration);

/**
 * @brief Réinitialise le temps de début du message.
 *
 * @param message Le message à modifier.
 */
void reset_temporary_message(TemporaryMessage *message);

/**
 * @brief Définit la durée d'affichage d'un message temporaire.
 *
 * @param message Le message temporaire dont on souhaite définir la durée.
 * @param duration La durée en millisecondes pendant laquelle le message sera affiché.
 */
void temporary_message_set_duration(TemporaryMessage *message, int duration);

/**
 * @brief Définit le texte du message.
 *
 * @param message Le message à modifier.
 * @param text Le nouveau texte du message.
 */
void temporary_message_set_text(TemporaryMessage *message, Text text);

/**
 * @brief Dessine le message à l'écran.
 *
 * @param message Le message à dessiner.
 */
void draw_temporary_message(TemporaryMessage message);

/**
 * @brief Libère la mémoire allouée pour le message temporaire.
 *
 * @param message Le message à libérer.
 */
void free_temporary_message(TemporaryMessage *message);

#endif