CC=ccache clang
CFLAGS=-Llib/ -llogger
CWARNS=-Wall -Werror
OPTI=-O3 -Os


# Use this for creating release libraries...
release:
	$(CC) $(CWARNS) $(OPTI) -c src/logger.c
	mv *.o obj/
	ar rcs lib/liblogger.a obj/logger.o obj/colours.o


# ...and debug libraries
debug:
	$(CC) $(CWARNS) -g -c src/logger.c
	mv *.o obj/
	ar rcs lib/liblogger.a obj/logger.o obj/colours.o


test:
	$(CC) $(CWARNS) -g src/main.c -o bin/test $(CFLAGS)
	bin/test


valgrind:
	valgrind bin/test