#include <stdio.h>

#define SUCCESS 1
#define FAILURE -1
#define NUM 10
int queue[NUM];

void init(int* front,int* rear){
    *front=0;
    *rear=0;
}
//(*rear+1)%NUM==front  ←満杯の判定
/*例えば、NUM=5で[10,20,30,40,50]のとき、frontは[0]を指し、rearは[4]を指している。
　ここで、((*rear+1)%NUM)==frontは、(4+1)%5==0となり、満杯であることが分かる*/
int enqueue(int data,int* front,int* rear){
    if(((*rear+1)%NUM)==*front){
        return FAILURE;
    }
    queue[*rear]=data;
    *rear=(*rear+1)%NUM;  //rearが[2]を指しているとき、(2+1)%5=3で次の要素[3]を指せている
    return SUCCESS;
}

int dequeue(int* data,int* front,int* rear){
    if(*front==*rear){
        printf("空です\n");
        return FAILURE;
    }
    *data=queue[*front];
    *front=(*front+1)%NUM;
    return SUCCESS;
}

void show(int front,int rear){
    int i=front;
    while(i != rear){
        printf("%d ",queue[i]);
        i=(i+1)%NUM;
    }
    printf("\n");
}

int main(){
    int data,front,rear;

    init(&front,&rear);

    for(int i=1;i<=NUM;i++){
        if(enqueue(i*10,&front,&rear)==SUCCESS){
            printf("ENQUEUE : %d\n",i*10);
        }
    }
    show(front,rear);
    
    while(dequeue(&data,&front,&rear)==SUCCESS){
        printf("DEQUEUE : %d\n",data);
    }
    return 0;
}