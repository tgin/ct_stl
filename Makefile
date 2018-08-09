testframe:testframe.o LinkList.o
	gcc -o testframe  testframe.o LinkList.o
	
testframe.o:testframe.c LinkList.c LinkList.h
	gcc -c -g testframe.c LinkList.c
	
LinkList.o:LinkList.c LinkList.h
	gcc -c -g LinkList.c

clean:
	rm -f testframe testframe.o LinkList.o
