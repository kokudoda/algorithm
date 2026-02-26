#include <stdio.h>

#define NUM 10
int array[NUM];


void buble_sort()
{
    for(int i = 0; i < NUM;i++){
        for(int j = i+1; j < NUM; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(void)
{
    int num;
    
    printf("enter numbers\n");
    for(int i = 0; i < NUM; i++){
        scanf("%d",&num);
        array[i] = num;
    }

    buble_sort();

    for(int i = 0; i < NUM; i++){
        printf("%d ",array[i]);
    }
    
    return 0;
}

