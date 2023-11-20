CC = gcc 
CFLAGS = -W -Wall -std=c89 -pedantic -O2
CLIBS = -lm -lMLV

# List of object files
MODEL = window.o 
UTILS = utils.o dimension.o position.o animation.o image.o text.o



all: build simple-clean

build: main.o $(MODEL) $(UTILS)
	$(CC) main.o $(MODEL) $(UTILS) -o main $(CLIBS)

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


	
# simple-clean removes all the .o files
simple-clean:
	rm -rf *.o

# Clean removes all the .o files and the executable
clean: simple-clean
	rm -rf main
