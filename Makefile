CC = gcc 
CFLAGS = -W -Wall -std=c89 -pedantic -O2
CLIBS = -lm -lMLV

# List of object files
MANAGER = event_manager.o keyboard_manager.o mouse_manager.o
MODEL = window.o heros.o projectile.o enemy.o klaed.o nairan.o nautolan.o asteroid.o player.o bonus.o
UTILS = utils.o dimension.o position.o animation.o image.o text.o hitbox.o
CONTROLLERS = heros_controller.o enemy_controller.o projectile_controller.o collision_controller.o asteroid_controller.o players_controller.o bonus_controller.o


all: build simple-clean

build: main.o $(MODEL) $(UTILS) $(MANAGER) $(CONTROLLERS)
	$(CC) main.o $(MODEL) $(UTILS) $(MANAGER) $(CONTROLLERS) -o main $(CLIBS)

# ----------- #
# Main file 
# ----------- #

main.o: ./src/main.c
	$(CC) $(CFLAGS) -c ./src/main.c


# ------------------ #
# Models
# ------------------ #

window.o: ./src/game/model/window/window.c
	$(CC) $(CFLAGS) -c ./src/game/model/window/window.c

heros.o: ./src/game/model/heros.c
	$(CC) $(CFLAGS) -c ./src/game/model/heros.c

projectile.o: ./src/game/model/projectile.c
	$(CC) $(CFLAGS) -c ./src/game/model/projectile.c
	
enemy.o: ./src/game/model/enemy/enemy.c
	$(CC) $(CFLAGS) -c ./src/game/model/enemy/enemy.c

klaed.o: ./src/game/model/enemy/klaed.c
	$(CC) $(CFLAGS) -c ./src/game/model/enemy/klaed.c

nairan.o: ./src/game/model/enemy/nairan.c
	$(CC) $(CFLAGS) -c ./src/game/model/enemy/nairan.c

nautolan.o: ./src/game/model/enemy/nautolan.c
	$(CC) $(CFLAGS) -c ./src/game/model/enemy/nautolan.c

asteroid.o: ./src/game/model/asteroid/asteroid.c
	$(CC) $(CFLAGS) -c ./src/game/model/asteroid/asteroid.c

player.o: ./src/game/model/player.c
	$(CC) $(CFLAGS) -c ./src/game/model/player.c

bonus.o: ./src/game/model/bonus/bonus.c
	$(CC) $(CFLAGS) -c ./src/game/model/bonus/bonus.c

# ------------------ #
# Utils
# ------------------ #
utils.o: ./src/utils/utils.c
	$(CC) $(CFLAGS) -c ./src/utils/utils.c

dimension.o: ./src/utils/dimension/dimension.c
	$(CC) $(CFLAGS) -c ./src/utils/dimension/dimension.c

position.o: ./src/utils/position/position.c
	$(CC) $(CFLAGS) -c ./src/utils/position/position.c

animation.o: ./src/utils/animation/animation.c
	$(CC) $(CFLAGS) -c ./src/utils/animation/animation.c

image.o: ./src/utils/image/image.c
	$(CC) $(CFLAGS) -c ./src/utils/image/image.c

text.o: ./src/utils/text/text.c
	$(CC) $(CFLAGS) -c ./src/utils/text/text.c

hitbox.o: ./src/utils/hitbox/hitbox.c
	$(CC) $(CFLAGS) -c ./src/utils/hitbox/hitbox.c


# ------------------ #
# Manager
# ------------------ #

event_manager.o: ./src/game/manager/event_manager/event_manager.c
	$(CC) $(CFLAGS) -c ./src/game/manager/event_manager/event_manager.c

keyboard_manager.o: ./src/game/manager/event_manager/keyboard_manager/keyboard_manager.c
	$(CC) $(CFLAGS) -c ./src/game/manager/event_manager/keyboard_manager/keyboard_manager.c

mouse_manager.o: ./src/game/manager/event_manager/mouse_manager/mouse_manager.c
	$(CC) $(CFLAGS) -c ./src/game/manager/event_manager/mouse_manager/mouse_manager.c


# ------------------ #
# Controller
# ------------------ #

heros_controller.o: ./src/game/controller/heros_controller/heros_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/heros_controller/heros_controller.c

enemy_controller.o: ./src/game/controller/enemy_controller/enemy_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/enemy_controller/enemy_controller.c

projectile_controller.o: ./src/game/controller/projectile_controller/projectile_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/projectile_controller/projectile_controller.c

collision_controller.o: ./src/game/controller/collision_controller/collision_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/collision_controller/collision_controller.c

asteroid_controller.o: ./src/game/controller/asteroid_controller/asteroid_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/asteroid_controller/asteroid_controller.c

players_controller.o: ./src/game/controller/players_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/players_controller.c

bonus_controller.o: ./src/game/controller/bonus_controller/bonus_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/bonus_controller/bonus_controller.c

# simple-clean removes all the .o files
simple-clean:
	rm -rf *.o

# Clean removes all the .o files and the executable
clean: simple-clean
	rm -rf main
