#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100
#define ERROR 0
#define OK 1

typedef int QElemType;
typedef int Status;
typedef struct{
	QElemType *base;
	int front;//the front of the queue
	int rear;
	int length;// the size of the queue, not the number of elements
}SqQueue;
/*
* the followings are base functions of a queue
*/
Status InitQueue(SqQueue &Q,int QLength){
	Q.base=(QElemType*)malloc(QLength*sizeof(QElemType));
	if(!Q.base){
		return ERROR;
	}
	Q.front=Q.rear=0;
	Q.length=QLength;
	return OK;
}

Status EnQueue(SqQueue &Q,QElemType e,int &length){ // insert an element into the queue
	if(Q.length==length) return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%Q.length;
	length++;
	return OK;
}
Status DeQueue(SqQueue &Q,QElemType &e,int &length){//delete an element from the queue
	if(length==0) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%Q.length;
	length--;
	return OK;
}

int main(){
	
	SqQueue squeue;
	QElemType e;
	int length=0,n,m;
	int i=0,TempElem;
	scanf("%d %d",&n,&m);
	InitQueue(squeue,m);
	while(i<n){
		scanf("%d",&TempElem);
		switch(TempElem){
		case 0:if(DeQueue(squeue,e,length)){
					printf("%d\n",e);
			   } break;
		default:if(EnQueue(squeue,TempElem,length)){
					break;
				}else{
					printf("No\n");
				}break;
		}
		i++;
	}
	return 0;
}