CC=g++
CFLAGS=-pedantic -O2
LFLAGS=-lncurses
OBJS=objs/bucket.o objs/main.o 

all: objs ./buckets

debug: CFLAGS += -DDEBUG -g
debug: clean all

./buckets: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o ./buckets

objs/bucket.o: src/bucket.cpp src/bucket.hpp
	$(CC) $(CFLAGS) -c src/bucket.cpp -o objs/bucket.o

objs/main.o: src/main.cpp src/menu_wrapper/menu.hpp
	$(CC) $(CFLAGS) -c src/main.cpp -o objs/main.o

objs:
	mkdir objs
clean_objs:
	if [ "objs" != "." -a -d "objs" ]; then rm -r "objs"; fi
clean_bin:
	rm -f ./buckets
clean: clean_objs clean_bin
new: clean all
run: all
	././buckets

