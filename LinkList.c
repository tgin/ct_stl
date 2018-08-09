#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinkList.h"


typedef struct _LinkList{
	LinkListNode header;
	int length;
}TLinkList;



LinkList* LinkList_Create(){
	TLinkList* ret=NULL;
	ret=(TLinkList*)malloc(sizeof(TLinkList));
	memset(ret,0,sizeof(TLinkList));
	ret->header.next=NULL;
	ret->length=0;
	return ret;
}



void LinkList_Destory(LinkList* list){
	if(list!=NULL){
		free(list);
		list=NULL;
	}
	return ;
}


void LinkList_Clear(LinkList* list){
	TLinkList* tList=NULL;
	if(list==NULL){
		Printf("func LinkList_Clear error: the list is NULL");
		return ;
	}
	tList=(TLinkList*)list;
	tList->header.next=NULL;
	tList->length=0;
	return ;
}

int LinkList_Length(LinkList* list){
	TLinkList* tList=NULL;
	if(list==NULL){
		Printf("func LinkList_Length error: the list is NULL");
		return-1;
	}
	tList=(TLinkList*)list;
	return tList->length;
}

int LinkList_Insert(LinkList* list,LinkListNode* node,int pos){
	if(list==NULL || node==NULL || pos<=0){
		Printf("func LinkList_Insert error: list or node or pos illegal");
		return -1;
	}
	int i=0;
	TLinkList* tList=NULL;
	LinkListNode* current=NULL;
	
	tList=(TLinkList*)list;
	current=&tList->header;

	for(i=0;i<pos && (current->next!=NULl);++i){
	current=current->next;
	}

	node->next=current->next;
	current->next=node;

	tList->length++;

	return 0;
}

LinkListNode* LinkList_Get(LinkList* list,int pos){
	int i=0;
	TLinkList* tList=NULL;
	LinkListNode* current=NULL;
	if(list==NULL || pos<0){
		Printf("func LinkList_Get error: list or pos illegal");
		return NULL;
	}

	tList=(TLinkList*)list;
	current=&tList->header;
	for(i=0;i<pos && current->next!=NULL;++i){
		current=current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list,int pos){
	int i=0;
	TLinkList* tList=NULL;
	LinkListNode* current=NULL;
	LinkListNode* tmp=NULL;
	if(list==NULL || pos<0){
		printf("func LinkList_Delete error: list or pos illegal");
		return NULL;
	}

	tList=(TLinkList*)list;
	current=&tList->header;
	for(i=0;i<pos && current->next!=NULL;++i){
		current=current->next;
	}

	tmp=current->next;
	current->next=tmp->next;
	return tmp;
}
