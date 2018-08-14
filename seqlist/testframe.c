#include<stdio.h>
#include<stdlib.h>
#include "seqlist.h"

SeqList* SeqList_Create(int capacity){
	SeqList* list=NULL;
	list=(SeqList *)malloc(sizeof(SeqList *));
	if(list==NULL){
		printf("func SeqList_Create error\n");
		return NULL;
	}	
	return list;
}

void SeqList_Destory(SeqList* list){
	return ;
}

void SeqList_Clear(SeqList* list){
	return ;
}

int SeqList_Length(SeqList* list){
	return 0;
}

int SeqList_Insert(SeqList* list,SeqListNode* node,int pos){
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list,int pos){
	return NULL;
}

SeqListNode* SeqList_Delete(SeqList* list,int pos){
	return NULL;
}
