#include "../../../../include/game/manager/game_manager/backup_manager.h"
#include <stdio.h>
#include <stdlib.h>

static void read_saved_games(BackupManager *manager);

BackupManager construct_backup_manager()
{
    BackupManager manager;
    manager.backup_list.backups = (Backup *)malloc(sizeof(Backup) * MAX_BACKUPS);

    manager.backup_list.backups_count = 0;
    manager.best_score_list.best_scores_count = 0;

    read_saved_games(&manager);
    read_best_scores(&manager);

    return manager;
}

void save_game(GameManager *game_manager, int slot)
{
    Backup backup;
    char filename[256];
    FILE *file;

    if (slot < 0 || slot >= MAX_BACKUPS)
    {
        return;
    }

    backup.game_state = *game_manager;
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

    *game = manager->backup_list.backups[slot].game_state;
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

        if (fread(&(manager->backup_list.backups[i]), sizeof(Backup), 1, file) != 1)
        {
            fprintf(stderr, "Error while reading backup %d\n", i);
            continue;
        }

        fclose(file);
        manager->backup_list.backups_count++;
    }
}

void read_best_scores(BackupManager *backup_manager)
{
    FILE *file = fopen("./.bin/scores/best_scores.bin", "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    if (fread(&backup_manager->best_score_list, sizeof(BestScoreList), 1, file) != 1)
    {
        fprintf(stderr, "Error while reading best scores.\n");
    }
    fclose(file);
}

static void write_best_scores(BackupManager *backup_manager)
{
    FILE *file = fopen("./.bin/scores/best_scores.bin", "wb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    if (fwrite(&backup_manager->best_score_list, sizeof(BestScoreList), 1, file) != 1)
    {
        fprintf(stderr, "Error while writing best scores.\n");
    }

    fclose(file);
}

int compare_best_scores(const void *a, const void *b)
{
    const BestScore *scoreA = (const BestScore *)a;
    const BestScore *scoreB = (const BestScore *)b;

    return (scoreB->score - scoreA->score);
}

void save_best_scores(BackupManager *backup_manager, GameManager game_manager)
{
    int i = 0;
    for (; i < game_manager.players.nb_players; i++)
    {
        if (backup_manager->best_score_list.best_scores_count < MAX_BACKUPS ||
            game_manager.players.players[i].score > backup_manager->best_score_list.best_scores[MAX_BACKUPS - 1].score)
        {
            if (backup_manager->best_score_list.best_scores_count < MAX_BACKUPS)
            {
                backup_manager->best_score_list.best_scores[backup_manager->best_score_list.best_scores_count].score = game_manager.players.players[i].score;
                strcpy(backup_manager->best_score_list.best_scores[backup_manager->best_score_list.best_scores_count].name, game_manager.players.players[i].username);
                backup_manager->best_score_list.best_scores[backup_manager->best_score_list.best_scores_count].timestamp = time(NULL);

                backup_manager->best_score_list.best_scores_count++;
            }
            else
            {
                backup_manager->best_score_list.best_scores[MAX_BACKUPS - 1].score = game_manager.players.players[i].score;
                strcpy(backup_manager->best_score_list.best_scores[MAX_BACKUPS - 1].name, game_manager.players.players[i].username);
                backup_manager->best_score_list.best_scores[MAX_BACKUPS - 1].timestamp = time(NULL);
            }

            qsort(backup_manager->best_score_list.best_scores, backup_manager->best_score_list.best_scores_count, sizeof(BestScore), compare_best_scores);
        }
    }

    write_best_scores(backup_manager);
}

void free_backup_manager(BackupManager *manager)
{
    free(manager->backup_list.backups);
}