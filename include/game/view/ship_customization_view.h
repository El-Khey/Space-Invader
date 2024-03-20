#ifndef SHIP_CUSTOMIZATION_H
#define SHIP_CUSTOMIZATION_H

#include "../../main.h"
#include "../../gui/button/button.h"
#include "../../gui/shape/shape.h"
#include "../../utils/text/text.h"
#include "../../utils/animation/animation.h"

#define MAX_SHIP_LEVEL 4
#define CUSTOMIZATION_NUMBER_OF_BUTTONS 2
#define BAR_WIDTH 200
#define BAR_HEIGHT 75

/**
 * @brief Type énuméré pour définir le type de modalité de personnalisation du vaisseau.
 */
typedef enum
{
    MODAL_ENGINE, /**< Modalité du moteur */
    MODAL_WEAPON  /**< Modalité de l'arme */
} ShipCustomizationModalType;

/**
 * @brief Structure représentant la barre de personnalisation du vaisseau.
 */
typedef struct
{
    Rectangle background;                           /**< Rectangle de fond */
    Button button[CUSTOMIZATION_NUMBER_OF_BUTTONS]; /**< Tableau de boutons */
} ShipCustomizationBar;

/**
 * @brief Structure représentant la modalité de personnalisation du vaisseau.
 */
typedef struct
{
    Text title;           /**< Titre */
    Rectangle background; /**< Rectangle de fond */

    Button engine_buttons[MAX_SHIP_LEVEL];      /**< Tableau de boutons de moteur */
    Button engine_text_buttons[MAX_SHIP_LEVEL]; /**< Tableau de boutons de texte de moteur */

    Button weapon_buttons[MAX_SHIP_LEVEL];      /**< Tableau de boutons d'arme */
    Button weapon_text_buttons[MAX_SHIP_LEVEL]; /**< Tableau de boutons de texte d'arme */
} ShipCustomizationModal;

/**
 * @brief Structure représentant la vue de personnalisation du vaisseau.
 */
typedef struct
{
    ShipCustomizationBar bar;                                      /**< Barre de personnalisation */
    ShipCustomizationModal modal[CUSTOMIZATION_NUMBER_OF_BUTTONS]; /**< Tableau de modalités */
    int active_modal;                                              /**< Modalité active */
    int is_modal_active;                                           /**< Indicateur d'activation de la modalité */
} ShipCustomizationView;

/**
 * @brief Construit une vue de personnalisation de vaisseau pour un joueur donné.
 *
 * @param player_id L'identifiant du joueur.
 * @return La vue de personnalisation de vaisseau construite.
 */
ShipCustomizationView construct_ship_customization(int player_id);

/**
 * @brief Obtient le prix d'une arme donnée.
 *
 * @param weapon_type Le type d'arme.
 * @return Le prix de l'arme.
 */
int get_weapon_price(int weapon_type);

/**
 * @brief Obtient le prix d'un moteur donné.
 *
 * @param engine_type Le type de moteur.
 * @return Le prix du moteur.
 */
int get_engine_price(int engine_type);

/**
 * @brief Dessine la vue de personnalisation de vaisseau avec la position de la souris.
 *
 * @param ship_customization La vue de personnalisation de vaisseau.
 * @param mouse_position La position de la souris.
 */
void draw_ship_customization(ShipCustomizationView ship_customization, Position mouse_position);

/**
 * @brief Libère la mémoire allouée pour la vue de personnalisation de vaisseau.
 *
 * @param ship_customization Un pointeur vers la vue de personnalisation de vaisseau.
 */
void free_ship_customization(ShipCustomizationView *ship_customization);

#endif