#ifndef BACKUP_MANAGER_H_
#define BACKUP_MANAGER_H_

#include "./game_manager.h"

#define MAX_BACKUPS 10
#define TEXT_LENGTH_MAX 20

/**
 * @brief Structure représentant un meilleur score.
 */
typedef struct
{
    char name[TEXT_LENGTH_MAX]; /**< Nom du joueur */
    int score;                  /**< Score obtenu */
    int timestamp;              /**< Horodatage du score */
} BestScore;

/**
 * @brief Structure représentant une sauvegarde.
 */
typedef struct Backup
{
    GameManager game_state; /**< État du jeu sauvegardé */
    time_t timestamp;       /**< Horodatage de la sauvegarde */
    int slot;               /**< Emplacement de la sauvegarde */
} Backup;

/**
 * @brief Structure représentant une liste de sauvegardes.
 */
typedef struct
{
    Backup *backups;   /**< Tableau de sauvegardes */
    int backups_count; /**< Nombre de sauvegardes */
} BackupList;

/**
 * @brief Structure représentant une liste de meilleurs scores.
 */
typedef struct
{
    BestScore best_scores[MAX_BACKUPS]; /**< Tableau de meilleurs scores */
    int best_scores_count;              /**< Nombre de meilleurs scores */
} BestScoreList;

/**
 * @brief Structure représentant le gestionnaire de sauvegardes.
 */
typedef struct
{
    BackupList backup_list;        /**< Liste de sauvegardes */
    BestScoreList best_score_list; /**< Liste de meilleurs scores */
} BackupManager;

/**
 * @brief Cette fonction crée un BackupManager.
 * Le BackupManager est utilisé pour sauvegarder et charger des parties de jeu et les meilleurs scores à partir de fichiers binaires.
 *
 * @return BackupManager
 */
BackupManager construct_backup_manager();

/**
 * @brief Cette fonction sauvegarde une partie de jeu dans un fichier binaire.
 *
 * @param game_manager Le jeu à sauvegarder
 * @param slot L'emplacement dans lequel la partie sera sauvegardée
 */
void save_game(GameManager *game_manager, int slot);

/**
 * @brief Cette fonction lit les meilleurs scores à partir des fichiers binaires.
 *
 * @param backup_manager Le BackupManager
 */
void read_best_scores(BackupManager *backup_manager);

/**
 * @brief Cette fonction sauvegarde les meilleurs scores dans un fichier binaire.
 *
 * @param backup_manager Le BackupManager
 * @param game_manager Le jeu à sauvegarder
 */
void save_best_scores(BackupManager *backup_manager, GameManager game_manager);

/**
 * @brief Cette fonction charge la partie du jeu qui n'est pas sauvegardée dans le fichier binaire,
 * tels que les animations, les images, les textes MLV, etc.
 *
 * @param manager Le BackupManager
 * @param game Le jeu à charger
 * @param slot L'emplacement dans lequel la partie est sauvegardée
 */
void load_game(BackupManager *manager, GameManager *game, int slot);

/**
 * @brief Cette fonction libère la mémoire allouée pour le BackupManager.
 *
 * @param manager Le BackupManager
 */
void free_backup_manager(BackupManager *manager);

#endif