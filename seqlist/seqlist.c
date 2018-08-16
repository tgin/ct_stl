#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqlist.h"

typedef struct _tag_SeqList{
	int length;
	int capacity;
	unsigned int* node;
}TSeqList;


SeqList* SeqList_Create(int capacity){
	TSeqList* list=NULL;

	list=(TSeqList*)malloc(sizeof(TSeqList));
	if(list==NULL){
		printf("func SeqList_Create error: malloc list fail\n");
		return NULL;
	}
	memset(list,0,sizeof(TSeqList));

	list->node=(unsigned int*)malloc(sizeof(unsigned int*)*capacity);
	if(list->node==NULL){
		printf("func SeqList_Create error: malloc node fail\n");
		return NULL;
	}
	list->capacity=capacity;
	list->length=0;
	return list;
}



void SeqList_Destory(SeqList* list){
	if(list==NULL)
		return ;
	TSeqList* tlist=NULL;
	tlist=(TSeqList*)list;
	if(tlist->node!=NULL)
		free(tlist->node);
	free(tlist);
	return ;
}

void SeqList_Clear(SeqList* list){
	TSeqList* tlist=NULL;
	if(list==NULL)
		return ;
	tlist=(TSeqList*)list;

	tlist->length=0;

	return ;
}

int SeqList_Length(SeqList* list){
	if(list==NULL){
		printf("func SeqList_Length error: list is NULL\n");
		return -1;
	}

	TSeqList* tlist=NULL;
	tlist=(TSeqList*)list;
	return tlist->length;
}



int SeqList_Insert(SeqList* list,SeqListNode* node,int pos){
	int i=0;
	if(list==NULL || node==NULL || pos<0){
		printf("func SeqList_Insert error: arg is invaild\n");
		return -1;
	}

	TSeqList* tlist=NULL;
	tlist=(TSeqList*)list;

	if(tlist->capacity<=tlist->length){
		printf("func SeqList_Insert error: list is full\n");
		return -2;
	}

	if(pos>=tlist->length){
		pos=tlist->length;
	}

	for(i=tlist->length;i>pos;--i){
		tlist->node[i]=tlist->node[i-1];
	}
	tlist->node[i]=(unsigned int)node;
	tlist->length++;
	return 0;
}




SeqListNode* SeqList_Get(SeqList* list,int pos){
	SeqListNode* ret=NULL;
	if(list==NULL || pos<0){
		printf("func SeqList_Get error: arg is invaild\n");
		return NULL;
	}
	TSeqList* tlist=NULL;
	tlist=(TSeqList*)list;
	ret=(SeqListNode*)tlist->node[pos];
	return ret;
}



SeqListNode* SeqList_Delete(SeqList* list,int pos){
	int i=0;
	SeqListNode* ret=NULL;
	if(list==NULL || pos<0){
		printf("func SeqList_Delete error: arg is invaild\n");
		return NULL;
	}

	TSeqList* tlist=NULL;
	tlist=(TSeqList*)list;
	
	ret=(SeqListNode*)tlist->node[pos];
	
	for(i=pos;i<tlist->length;i++){
		tlist->node[i]=tlist->node[i+1];
	}

	tlist->length--;
	return ret;
}
