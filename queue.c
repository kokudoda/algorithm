#include <stdio.h>
#include <stdlib.h>

#define NUM 128
#define SUCCESS     1
#define FAILURE    -1

void init(int* front,int* rear){
    *front=0;
    *rear=0;
}

int enqueue(int queue[],int data,int* rear){
    if(*rear>=NUM){
        return FAILURE;
    }
    else{
        queue[*rear]=data;
        (*rear)++;
        return SUCCESS;
    }
}

int dequeue(int queue[],int* data,int* front,int rear){
    if(*front==rear){
        return FAILURE;
    }
    else{
        *data=queue[*front];
        (*front)++;
        printf("DEQUEUE : %d\n",*data);
        return SUCCESS;
    }
}

int main(){
    int queue[NUM];
    int data,front,rear;

    init(&front,&rear);

    printf("数値の入力\n");
    for(int i=0;i<5;i++){
        scanf("%d",&data);
        printf("ENQUEUE : %d\n",data);
        enqueue(queue,data,&rear);
    }

    for(int i=0;i<5;i++){
        dequeue(queue,&data,&front,rear);
    }
    return 0;
}