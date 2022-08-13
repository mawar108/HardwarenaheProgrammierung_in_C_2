#
# In order to execute this "Makefile" just type "ma?ke"
#

OBJS	= game.o monster.o player.o sound.o texture.o main.o
SOURCE	= game.c monster.c player.c sound.c texture.c main.c
#TOPDIR := ~\
#SRCDIR := $(TOPDIR)
#BINDIR := $(TOPDIR)
#SOURCE := $(shell find $(SRCDIR) -name "*.c") 
#OBJS := $(patsubst %.c, %.o, $(SOURCE))
HEADER	= game.h monster.h player.h sound.h texture.h
OUT		= main
CC		= gcc
FLAGS	= -g -c -Wall
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: main

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

# create/compile the individual files >>separately<<
game.o: game/game.c game/game.h sound/sound.h texture/texture.h player/player.h monster/monster.h
	$(CC) $(FLAGS) game/game.c

monster.o: monster/monster.c monster/monster.h
	$(CC) $(FLAGS) monster/monster.c

player.o: player/player.c player/player.h
	$(CC) $(FLAGS) player/player.c 

sound.o: sound/sound.c sound/sound.h
	$(CC) $(FLAGS) sound/sound.c 

texture.o: texture/texture.c texture/texture.h
	$(CC) $(FLAGS) texture/texture.c 

main.o: main.c game/game.h
	$(CC) $(FLAGS) main.c 


# clean house
clean:
	rm -f $(OBJS) $(OUT)
