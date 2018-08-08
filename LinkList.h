//data:2018-08-08
//author:ct 
//linux 14.04 x64 
//vim with YCM


#ifndef LinkList_H
#define LinkList_H



typedef void LinkList;

typedef struct _LinkListNode{
	struct _LinkListNode* next;
}LinkListNode;//


LinkList* LinkList_Create();

void LinkList_Destory(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list,LinkListNode* node,int pos);

LinkListNode* LinkList_Get(LinkList* list,int pos);

LinkListNode* LinkList_Delete(LinkList* list,int pos);

#endif






