#include <stdio.h>

#define NUM 10
int array[NUM];


void buble_sort()
{
    for(int i = 0; i < NUM - 1;i++){
        for(int j = 0; j < NUM - 1 - i; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
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

