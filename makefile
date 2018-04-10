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

clean:
	rm -f livewall
