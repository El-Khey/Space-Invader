#ifndef BACKUP_MANAGER_H_
#define BACKUP_MANAGER_H_

#include "./game_manager.h"

#define MAX_BACKUPS 10
#define TEXT_LENGTH_MAX 20

typedef struct
{
    char name[TEXT_LENGTH_MAX];
    int score;
    int timestamp;
} BestScore;

typedef struct Backup
{
    GameManager game_state;
    time_t timestamp;
    int slot;
} Backup;

typedef struct
{
    Backup *backups;
    int backups_count;
} BackupList;

typedef struct
{
    BestScore best_scores[MAX_BACKUPS];
    int best_scores_count;
} BestScoreList;

typedef struct
{
    BackupList backup_list;
    BestScoreList best_score_list;
} BackupManager;

BackupManager construct_backup_manager();

void save_game(GameManager *game_manger, int slot);

void read_best_scores(BackupManager *backup_manager);

void save_best_scores(BackupManager *backup_manager, GameManager game_manager);

void load_game(BackupManager *manager, GameManager *game, int slot);

void free_backup_manager(BackupManager *manager);

#endif