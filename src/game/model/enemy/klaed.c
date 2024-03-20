#include "../../../../include/game/model/enemy/klaed.h"

void initialize_klaed_enemy(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {

    case BATTLECRUISER:
        enemy->speed = 2;
        enemy->damage = 3;

        enemy->health = 15;
        enemy->score = 15;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Battlecruiser.png", 30, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Battlecruiser.png", 14, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;

    case BOMBER:
        enemy->speed = 3;
        enemy->damage = 1;
        enemy->health = 2;

        enemy->score = 5;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Bomber.png", 8, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Bomber.png", 10, enemy->dimension, BACKWARD);

        break;

    case DREADNOUGHT:
        enemy->speed = 2;
        enemy->damage = 7;
        enemy->health = 65;

        enemy->score = 45;
        enemy->list.active_bullet_type = RED_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Dreadnought.png", 60, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Dreadnought.png", 12, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Dreadnought.png", 12, enemy->dimension, BACKWARD);
        break;

    case FIGHTER:
        enemy->speed = 3;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 5;
        enemy->list.active_bullet_type = RED_RAY;
        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Fighter.png", 6, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Fighter.png", 9, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Fighter.png", 10, enemy->dimension, BACKWARD);
        break;

    case FRIGATE:
        enemy->speed = 3;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 15;
        enemy->list.active_bullet_type = RED_TORPEDO;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Frigate.png", 6, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Frigate.png", 9, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Frigate.png", 12, enemy->dimension, BACKWARD);
        break;

    case SCOUT:
        enemy->speed = 3;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 15;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Scout.png", 6, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Scout.png", 10, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Scout.png", 10, enemy->dimension, BACKWARD);
        break;

    case SUPPORT:
        enemy->speed = 4;
        enemy->damage = 1;
        enemy->health = 5;

        enemy->score = 15;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Support.png", 10, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Support.png", 10, enemy->dimension, BACKWARD);
        break;

    case TORPEDO:
        enemy->speed = 3;
        enemy->damage = 1;
        enemy->health = 5;

        enemy->score = 15;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Torpedo.png", 10, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Torpedo.png", 10, enemy->dimension, BACKWARD);
        break;

    default:
        /**
         * @brief En cas d'erreur, nous définissons l'ennemi à une valeur par défaut.
         * Ceci est une mesure de sécurité pour éviter un crash du jeu si le type d'ennemi n'est pas correctement défini,
         * par exemple si le type scout n'est pas présent pour toutes les classes d'ennemis.
         */
        enemy->speed = 2;
        enemy->damage = 3;

        enemy->health = 15;
        enemy->score = 15;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Battlecruiser.png", 30, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Battlecruiser.png", 14, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;
    }
}
