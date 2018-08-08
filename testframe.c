//date:2018-08-08
//author:ct 
//linux 14.04 x64
//vim with YCM



#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinkList.h"

typedef struct _Teacher{
	LinkListNode node;
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

	list=LinKList_Create();
	if(list==NULL){
		return ;
	}

	len=LinkList_Length(list);

}
