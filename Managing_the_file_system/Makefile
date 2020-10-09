CC := g++ -Wall -Werror
FLAGS := -std=c99
FLAG := -std=c11

.PHONY: all clean install uninstall rebuild

all: proc

proc: builds/main.o builds/commands.o
	$(CC) builds/main.o builds/commands.o -o proc

builds/main.o: main.cpp
	$(CC) -c main.cpp -o builds/main.o

builds/commands.o: commands.cpp
	$(CC) -c commands.cpp -o builds/commands.o

clean:
	find -name "*.o" -exec rm -rf {} +
	rm -rf ./bin/proc

install:
	sudo cp ./bin/proc /usr/bin/proc

uninstall:
	sudo rm -f /usr/bin/proc

rebuild: clean all