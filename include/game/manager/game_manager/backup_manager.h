#ifndef BACKUP_MANAGER_H_
#define BACKUP_MANAGER_H_

#include "./game_manager.h"

#define MAX_BACKUPS 10

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
} BackupManager;

BackupManager construct_backup_manager();

void save_game(GameManager *game, int slot);

void load_game(BackupManager *manager, GameManager *game, int slot);

void free_backup_manager(BackupManager *manager);

#endif