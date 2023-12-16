#ifndef SCORE_MENU_PAGE_H
#define SCORE_MENU_PAGE_H

#include "../../game/manager/game_manager/backup_manager.h"

#include "../../utils/text/text.h"
#include "../../gui/button/button.h"
#include "../../utils/utils.h"

#define MAX_BACKUP_BUTTONS 10
#define TEXT_LENGTH_MAX 20
#define BEST_SCORES 10

/**
 * @struct ScoreMenu
 * @brief Représente le menu des scores.
 *
 * Cette structure contient les informations nécessaires pour afficher et gérer le menu des scores.
 * Elle comprend un bouton de retour, un tableau de boutons pour les meilleurs scores et le nombre de meilleurs scores.
 */
typedef struct
{
    Button button_back;                             /** Bouton de retour */
    Button best_scores_buttons[MAX_BACKUP_BUTTONS]; /** Tableau de boutons pour les meilleurs scores */
    int best_scores_count;                          /** Nombre de meilleurs scores */
} ScoreMenu;

/**
 * @brief Construit un nouvel objet Page de menu des scores
 *
 * @return ScoreMenu
 */
ScoreMenu construct_score_menu_page(BackupManager backup_manager);

/**
 * @brief Dessine la page du menu des scores
 *
 * @param score_menu La page du menu des scores à dessiner
 * @param mouse_position La position de la souris
 */
void draw_score_menu_page(ScoreMenu score_menu, Position mouse_position);

#endif