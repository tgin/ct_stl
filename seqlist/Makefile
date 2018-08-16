CC=gcc

seqlist: testframe.o seqlist.o
	$(CC) -o seqlist testframe.o seqlist.o

testframe.o: testframe.c seqlist.c seqlist.h
	$(CC) -c -g -w testframe.c testframe.c

seqlist.o: seqlist.c seqlist.h
	$(CC) -c -g -w seqlist.c

clean:
	rm -rf *.o seqlist 
