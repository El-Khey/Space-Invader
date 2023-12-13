#ifndef BACKUP_MANAGER_H_
#define BACKUP_MANAGER_H_

#include "./game_manager.h"

#define MAX_BACKUPS 10
#define TEXT_LENGTH_MAX 20

typedef struct
{
    char name[TEXT_LENGTH_MAX];
    int score;
} BestScore;

typedef struct Backup
{
    GameManager game_state;
    time_t timestamp;
    int slot;
} Backup;

typedef struct BackupManager
{
    Backup *backups;
    int backups_count;

    BestScore best_scores[MAX_BACKUPS];
    int best_scores_count;
} BackupManager;

BackupManager construct_backup_manager();

void save_game(GameManager *game, int slot);

void load_game(BackupManager *manager, GameManager *game, int slot);

void free_backup_manager(BackupManager *manager);

#endif