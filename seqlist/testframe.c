#include<stdio.h>
#include<stdlib.h>
#include "seqlist.h"

typedef struct _Teacher{
	int age;
	char name[64];
}Teacher;




int main(){
	int ret=0;
	int i=0;
	SeqList* list=NULL;

	Teacher t1,t2,t3,t4,t5;
	t1.age=21;
	t2.age=22;
	t3.age=23;
	t4.age=24;
	t5.age=25;

	list=SeqList_Create(10);
	if(list==NULL){
		printf("create fail\n");
		return -1;
	}
	
	ret=SeqList_Insert(list,(SeqListNode*)&t1,0);
	ret=SeqList_Insert(list,(SeqListNode*)&t2,0);
	ret=SeqList_Insert(list,(SeqListNode*)&t3,0);
	ret=SeqList_Insert(list,(SeqListNode*)&t4,0);
	ret=SeqList_Insert(list,(SeqListNode*)&t5,0);

	for(i=0;i<SeqList_Length(list);i++){
		Teacher* tmp=(Teacher*)SeqList_Get(list,i);
		if(tmp==NULL){
			printf("SeqList_Get fail\n");
			return -1;
		}
		printf("tmp->age: %d\n",tmp->age);
	}	

	while(SeqList_Length(list)>0){
		SeqList_Delete(list,0);
	}
	return 0;
}


