CC := g++ -Wall -Werror
FLAGS := -std=c99
FLAG := -std=c11

.PHONY: all clean install uninstall rebuild

all: LiteSH

LiteSH: builds/main.o builds/LiteSH.o
	$(CC) builds/main.o builds/LiteSH.o -I./home/misha/Labs/Operation-System/LiteSH/libs/libinfo.so -ldl -o LiteSH

builds/main.o: main.cpp
	$(CC) -c main.cpp -o builds/main.o

builds/LiteSH.o: LiteSH.cpp
	$(CC) -c LiteSH.cpp -o builds/LiteSH.o

clean:
	find -name "*.o" -exec rm -rf {} +
	rm -rf ./bin/LiteSH

install:
	sudo cp ./bin/proc /usr/bin/LiteSH

uninstall:
	sudo rm -f /usr/bin/LiteSH

rebuild: clean all