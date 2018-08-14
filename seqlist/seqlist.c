#include <stdio.h>
#include <stdlib.h>
#include "seqlist.c"

typedef struct _tag_SeqList{
	int length;
	int capacity;
	unsigned int* node;
}TSeqList;


