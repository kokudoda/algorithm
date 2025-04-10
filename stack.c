#include <stdio.h>
#include <stdlib.h>

#define NUM 128
#define SUCCESS 1
#define FAILURE -1

int push(int stack[],int data,int* top){
    if(*top == NUM){
        return FAILURE;
    }
    else{
        stack[(*top)]=data;
        (*top)++;
        return SUCCESS;
    }
}

int pop(int stack[],int* data,int* top){
    if((*top) > 0){
        *data=stack[(*top)-1];
        (*top)--;
        printf("POP : %d\n",*data);
        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}

int main(){
    int stack[NUM];
    int data,top;
    top=0;

    printf("数字を入力してください\n");
    for(int i=0;i<5;i++){
        scanf("%d",&data);
        printf("PUSH : %d\n",data);
        push(stack,data,&top);
    }

    for(int i=0;i<5;i++){
        pop(stack,&data,&top);
    }
    return 0;
}