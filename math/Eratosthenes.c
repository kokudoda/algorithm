#include <stdio.h>

//1000‚Ü‚Å‘f”‚ğ•\¦
#define NUM 1000

//‘f”‚È‚ç1,‚»‚¤‚Å‚È‚¢‚È‚ç0‚ğ”z—ñ‚ÉŠi”[‚·‚é‚æ‚¤‚É‚·‚é
#define TRUE 1   
#define FALSE 0

char array[NUM + 1]; 

//‰Šú‰»ŠÖ”
void init()
{
    //‚·‚×‚Ä‘f”‚Å‰Šú‰»
    for(int i = 1; i <= NUM; i++){
        array[i] = TRUE; 
    }
    //1‚Í‘f”‚Å‚Í‚È‚¢‚Ì‚ÅFALSE‚Æ‚·‚é
    array[1] = FALSE; 
}

void Eratosthenes()
{   
    for(int i = 2; i <= NUM; i++){
        if(array[i]){
            //iˆÈŠO‚Ìi‚Ì”{”‚ÉFALSE‚ğŠi”[‚µ‚Ä‚¢‚­
            for(int j = i*2; j <= NUM; j += i){
                array[j] = FALSE;
            }
        }
    }
}

int main()
{
    init();

    Eratosthenes();

    for(int i = 2; i <= NUM; i++){
        if(array[i]){
            printf("%d ",i);
        }
    }
    return 0;
}