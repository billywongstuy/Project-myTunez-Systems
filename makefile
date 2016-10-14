GCC = gcc -g

all: myTunez.o song_node.o main.o
	$(GCC) myTunez.o song_node.o main.o -o tuneztest

myTunez.o: myTunez.c myTunez.h
	$(GCC) -c myTunez.c

song_node.o: song_node.c song_node.h
	$(GCC) -c song_node.c

main.o: main.c song_node.h myTunez.h
	$(GCC) -c main.c

clean:
	rm *.o
	rm *~

run: all
	./tuneztest
