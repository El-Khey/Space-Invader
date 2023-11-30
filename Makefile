CC = gcc 
CFLAGS = -W -Wall -std=c89 -pedantic -O2
CLIBS = -lm -lMLV

# List of object files
MANAGER = event_manager.o keyboard_manager.o mouse_manager.o
MODEL = window.o heros.o projectile.o enemy.o
UTILS = utils.o dimension.o position.o animation.o image.o text.o
CONTROLLERS = player_controller.o enemy_controller.o


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
	
enemy.o: ./src/game/model/enemy.c
	$(CC) $(CFLAGS) -c ./src/game/model/enemy.c

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

player_controller.o: ./src/game/controller/player_controller/player_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/player_controller/player_controller.c

enemy_controller.o: ./src/game/controller/enemy_controller/enemy_controller.c
	$(CC) $(CFLAGS) -c ./src/game/controller/enemy_controller/enemy_controller.c

	
# simple-clean removes all the .o files
simple-clean:
	rm -rf *.o

# Clean removes all the .o files and the executable
clean: simple-clean
	rm -rf main
