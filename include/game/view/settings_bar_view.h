#ifndef SETTINGS_BAR_VIEW_H_
#define SETTINGS_BAR_VIEW_H_

#include "../../gui/button/button.h"
#include "../../gui/shape/shape.h"
#include "../../utils/text/text.h"

/**
 * @brief Structure représentant un conteneur d'horloge.
 */
typedef struct
{
    Position position;   /**< La position du conteneur. */
    Dimension dimension; /**< Les dimensions du conteneur. */

    Text time_text; /**< Le texte de l'horloge. */
} ClockContainer;

/**
 * @brief Structure représentant le contenu de la barre de paramètres.
 */
typedef struct
{
    Dimension dimension; /**< Les dimensions du contenu. */
    Position position;   /**< La position du contenu. */

    Button music_button; /**< Le bouton de musique. */
    Button mute_button;  /**< Le bouton de sourdine. */

    Button pause_button;  /**< Le bouton de pause. */
    Button resume_button; /**< Le bouton de reprise. */
} settings_bar_content;

/**
 * @brief Structure représentant la vue de la barre de paramètres.
 */
typedef struct
{
    ClockContainer clock_container; /**< Le conteneur d'horloge. */
    settings_bar_content content;   /**< Le contenu de la barre de paramètres. */

    int is_music_on; /**< Indique si la musique est activée. */
    int is_paused;   /**< Indique si le jeu est en pause. */
} settings_bar_view;

/**
 * @brief Construit la vue de la barre de paramètres.
 *
 * @param settings_bar_view La vue de la barre de paramètres.
 */
settings_bar_view construct_settings_bar_view();

/**
 * @brief Définit l'état du bouton de musique.
 *
 * @param settings_bar_view La vue de la barre de paramètres.
 */
void set_music_button_state(settings_bar_view *settings_bar_view);

/**
 * @brief Dessine la vue de la barre de paramètres.
 *
 * @param settings_bar_view La vue de la barre de paramètres.
 * @param elapsed_time Le temps écoulé depuis le dernier dessin.
 */
void draw_settings_bar_view(settings_bar_view *settings_bar_view, int elapsed_time);

/**
 * @brief Libère la mémoire allouée pour la vue de la barre de paramètres.
 *
 * @param settings_bar_view La vue de la barre de paramètres.
 */
void free_settings_bar_view(settings_bar_view *settings_bar_view);

#endif