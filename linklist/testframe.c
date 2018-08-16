//date:2018-08-08
//author:ct 
//linux 14.04 x64
//vim with YCM



#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinkList.h"



//模拟一个业务节点
typedef struct _Teacher{
	LinkListNode node;//用业务节点包含我们定义的链表节点
	int age;
	char name[64];
}Teacher;

void main(){
	int len=0,ret=0;
	int i=0;
	
	LinkList* list=NULL;

	Teacher t1,t2,t3,t4,t5;
	t1.age=21;
	t2.age=22;
	t3.age=23;
	t4.age=24;
	t5.age=25;

	list=LinkList_Create();
	if(list==NULL){
		return ;
	}

	len=LinkList_Length(list);

	ret=LinkList_Insert(list,(LinkListNode*)&t1,0);
	ret=LinkList_Insert(list,(LinkListNode*)&t2,0);
	ret=LinkList_Insert(list,(LinkListNode*)&t3,0);
	ret=LinkList_Insert(list,(LinkListNode*)&t4,0);
	ret=LinkList_Insert(list,(LinkListNode*)&t5,0);

	//traversal
	for(i=0;i<LinkList_Length(list);++i){
		Teacher* tmp=(Teacher*)LinkList_Get(list,i);
		if(tmp==NULL){
		return;
		}
		printf("before tmp->age:%d\n",tmp->age);
	}


	LinkList_Delete(list,3);

	for(i=0;i<LinkList_Length(list);++i){
		Teacher* tmp=(Teacher*)LinkList_Get(list,i);
		if(tmp==NULL){
		return;
		}
		printf("after tmp->age:%d\n",tmp->age);
	}

	/*
	//delete
	while(LinkList_Length(list)>0){
		Teacher* tmp=(Teacher*)LinkList_Delete(list,0);
		if(tmp==NULL){
		return;
		}
		printf("Destory tmp->age:%d\n",tmp->age);
	}

*/ 
	LinkList_Destory(list);
	
	return ;
}





