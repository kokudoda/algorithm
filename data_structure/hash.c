#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

//status
#define EMPTY 0
#define USED 1
#define DELETE 2

struct hash_table_type{
    int data;
    int status;
};

//ハッシュテーブル
struct hash_table_type hash_table[SIZE];

//ハッシュテーブルの初期化関数
void init()
{
    for(int i = 0; i < SIZE; i++){
        hash_table[i].status = EMPTY;
    }
}

//ハッシュ値を返す関数
int hash(int key)
{
    return key % SIZE;
}

//挿入する関数
void insert(int key)
{
    int index = hash(key);
    for(int i = 0;i < SIZE; i++){
        int temp = (index + i) % SIZE;
        if(hash_table[temp].status == EMPTY || hash_table[temp].status == DELETE){
            hash_table[temp].data = key;
            hash_table[temp].status = USED;  //迥ｶ諷九ｒUSED縺ｫ縺吶ｋ
            return ;
        }
        if(hash_table[temp].status == USED && hash_table[temp].data == key){
            return ;
        }
    }
    printf("FULL\n");
}

//探索する関数
int search(int key)
{
    int index = hash(key);

    for(int i = 0; i < SIZE; i++){
        int temp = (index + i) % SIZE;
        
        //見つからなかった場合
        if(hash_table[temp].status == EMPTY){
            printf("Not Found\n");
            return -1;
        }

        if(hash_table[temp].status == USED && hash_table[temp].data == key){
            return temp; //添え字を返す
        }
    }
    return -1;
}

//削除する関数。状態をUSEDからDELETEに変える
void delete_data(int key)
{
    int index = search(key);
    if(index == -1){
        printf("Not found\n");
    }
    else{
        hash_table[index].status = DELETE;
    }
}

void show()
{
    for(int i = 0; i < SIZE; i++){
        if(hash_table[i].status == EMPTY){
            printf("[EMPTY]\n");
        }
        else if(hash_table[i].status == DELETE){
            printf("[DELETE]\n");
        }
        else{
            printf("[%d]\n",hash_table[i].data);
        }
    }
}

int main()
{
    int num;
    init();

    while(1){
        printf("Please enter a number(end at -1)\n");
        scanf("%d",&num);

        if(num == -1){
            break;
        }
        insert(num);
    }
    printf("\n");
    show();
    printf("\n");
    
    printf("Enter the number you want to find\n");
    scanf("%d",&num);
    int index = search(num);
    if(index == -1){
        printf("Not found\n");
    }
    else{
        printf("[%d] found\n",index);
    }

    printf("\n");

    printf("Enter the number you want to delete\n");
    scanf("%d",&num);
    delete_data(num);

    show();

}