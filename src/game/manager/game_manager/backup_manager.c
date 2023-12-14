#include "../../../../include/game/manager/game_manager/backup_manager.h"
#include <stdio.h>
#include <stdlib.h>

static void read_saved_games(BackupManager *manager);

BackupManager construct_backup_manager()
{
    BackupManager manager;
    manager.backups = (Backup *)malloc(sizeof(Backup) * MAX_BACKUPS);

    manager.backups_count = 0;
    read_saved_games(&manager);
    read_best_scores(&manager);

    return manager;
}

void save_game(GameManager *game, int slot)
{
    Backup backup;
    char filename[256];
    FILE *file;

    if (slot < 0 || slot >= MAX_BACKUPS)
    {
        return;
    }

    backup.game_state = *game;
    backup.timestamp = time(NULL);
    backup.slot = slot;

    sprintf(filename, "./.bin/games/backup%d", slot);

    file = fopen(filename, "wb");
    if (file == NULL)
    {
        return;
    }

    if (fwrite(&backup, sizeof(Backup), 1, file) != 1)
    {
        fprintf(stderr, "Error while writing backup %d\n", slot);
    }
    fclose(file);
}

void load_game(BackupManager *manager, GameManager *game, int slot)
{
    int i = 0;

    *game = manager->backups[slot].game_state;
    game->is_game_paused = 0;

    load_window_backup(&game->window);

    for (; i < game->players.nb_players; i++)
    {
        load_player_backup(&game->players.players[i]);
    }

    for (i = 0; i < game->controllers.enemy_controller.enemy_spawned; i++)
    {
        load_enemy_backup(&game->controllers.enemy_controller.enemies[i]);
    }

    for (i = 0; i < game->controllers.asteroid_controller.asteroid_spawned; i++)
    {
        load_asteroid_backup(&game->controllers.asteroid_controller.asteroids[i]);
    }

    for (i = 0; i < game->controllers.bonus_controller.bonus_spawned; i++)
    {
        load_bonus_backup(&game->controllers.bonus_controller.bonus[i]);
    }

    game->views.settings_bar_view = construct_settings_bar_view();
    game->views.pause_screen = construct_pause_screen();
    game->views.game_over_screen = construct_game_over_screen();
}

static void read_saved_games(BackupManager *manager)
{
    int i = 0;
    FILE *file;
    for (; i < MAX_BACKUPS; i++)
    {
        char filename[256];
        sprintf(filename, "./.bin/games/backup%d", i);

        file = fopen(filename, "rb");
        if (file == NULL)
        {
            continue;
        }

        if (fread(&(manager->backups[i]), sizeof(Backup), 1, file) != 1)
        {
            fprintf(stderr, "Error while reading backup %d\n", i);
            continue;
        }

        fclose(file);
        manager->backups_count++;
    }
}

void sort_by_score(BestScore *scores, int size)
{
    int i, j;
    BestScore temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (scores[j].score < scores[j + 1].score)
            {
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

void read_best_scores(BackupManager *backup_manager, GameManager game_manager)
{
    FILE *file = fopen("best_score.txt", "rb");

    if (file == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (i = 0; i < MAX_BACKUPS; i++)   
    {
        if (fread(&(backup_manager->best_score[i]), sizeof(BestScore), 1, file) != 1) 
        {
            fprintf(stderr, "Error while reading score %d\n", i);
        }
        
        backup_manager->best_scores_count++;
    }
    
    sort_by_score(backup_manager->best_score,backup_manager->backups_count);
    fclose(file);
}

void write_best_scores(GameManager game_manager, BackupManager *backup_manager)
{
    FILE *file = fopen("best_score.txt", "w");
    int i, j, k;
    BestScore tmp;

    if (file == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (i = 0; i < game_manager.players.nb_players; i++)
    {
        for (j = 0; i < backup_manager->best_scores_count; j++)
        {
            if (backup_manager->best_scores_count < MAX_BACKUPS)
            {
                if (backup_manager->best_scores[j].score < game_manager.players.players[i].score)
            }
            else
            {
                if (backup_manager->best_scores[j].score < game_manager.players.players[i].score)
                {
                    // Insert the sorted score
                    for (k = backup_manager->best_scores_count; k > j; k--)
                    {
                        backup_manager->best_scores[k] = backup_manager->best_scores[k - 1];
                    }
                    backup_manager->best_scores[j].score = game_manager.players.players[i].score;
                    strcpy(backup_manager->best_scores[j].name, game_manager.players.players[i].username);
                    backup_manager->best_scores_count++;
                }
            }
        }
    }

    else
    {
        if (backup_manager->best_scores[j].score < game_manager.players.players[i].score)
        {
            backup_manager->best_scores[j].score = game_manager.players.players[i].score;
            strcpy(backup_manager->best_scores[j].name, game_manager.players.players[i].username);
        }
    }
    fclose(file);
}

void free_backup_manager(BackupManager *manager)
{
    free(manager->backups);
}