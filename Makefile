CC=ccache gcc
CFLAGS=-Llib/ -llogger
CWARNS=-Wextra -Werror
OPTI=-O3 -Os


# Use this for creating release libraries...
release:
	$(CC) $(CWARNS) $(OPTI) -c -fPIE src/logger.c
	mv *.o obj/
	ar rcs lib/liblogger.a obj/logger.o obj/colours.o


# ...and debug libraries
debug:
	$(CC) $(CWARNS) -O1 -g -c -fPIE src/logger.c
	mv *.o obj/
	ar rcs lib/liblogger.a obj/logger.o obj/colours.o


test:
	$(CC) $(CWARNS) -O1 -fsanitize=address -g src/main.c -fPIE -o bin/test $(CFLAGS)
	bin/test
