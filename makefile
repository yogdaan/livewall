CC = gcc
CFLAGS= -g -Wall
INCLUDE = -L /usr/lib/x86_64-linux-gnu
LIBS = -lX11 -lXext -lXrender

all:
	${CC} livewall.c ${CFLAGS} ${INCLUDE} ${LIBS} -o livewall

install:
	install livewall '/usr/local/bin'

uninstall:
	rm -f '/usr/local/bin/livewall'

gui:
	gcc `pkg-config --cflags gtk+-3.0` -o gui gui.c `pkg-config --libs gtk+-3.0`
	
clean:
	rm -f livewall
