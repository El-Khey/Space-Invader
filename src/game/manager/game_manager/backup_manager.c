#include "../../../../include/game/manager/game_manager/backup_manager.h"
#include <stdio.h>
#include <stdlib.h>

static void read_saved_games(BackupManager *manager);

static int count_number_of_backups(BackupManager *manager);

BackupManager construct_backup_manager()
{
    BackupManager manager;
    printf("Constructing backup manager\n");

    manager.backups = (Backup *)malloc(sizeof(Backup) * MAX_BACKUPS);
    /**
        manager.backups_count = count_number_of_backups(&manager);
        read_saved_games(&manager);
     */
    manager.backups_count = 0;
    printf("> %d backups found\n", manager.backups_count);
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

static int count_number_of_backups(BackupManager *manager)
{
    int i = 0;
    int count = 0;
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

        Backup backup;
        if (fread(&backup, sizeof(Backup), 1, file) != 1)
        {
            fprintf(stderr, "Error while reading backup %d\n", i);
            fclose(file);
            continue;
        }

        fclose(file);
        count++;
    }
    return count;
}

static void read_saved_games(BackupManager *manager)
{
    int i = 0;
    FILE *file;
    printf("> Reading saved games\n");
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

void free_backup_manager(BackupManager *manager)
{
    free(manager->backups);
}