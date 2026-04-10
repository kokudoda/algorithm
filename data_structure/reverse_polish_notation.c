#include <stdio.h>

char pol[100];  //文字列として格納する配列
int stack[100];    //スタック

int rpn(); //逆ポーランド記法

void push(int* sp,int n);  //スタックにpushする関数
int pop(int* sp);          //スタックからpopする関数

int CtoI(char c);  //char型からint型に変換する関数

int main()
{ 
    printf(" >>> ");
    scanf("%s",pol);  //文字列として入力

    printf("ANSWER = %d\n",rpn());

    return 0;
}


int rpn()
{
    int first,second; //stackからpopした値を格納する変数
    int sp = 0;    //スタックポインタ
    int i;

    for(i = 0 ; pol[i] != '\0'; i++){
        //pol[i]が0~9の数値ならpush
        if('0' <= pol[i] && pol[i] <= '9'){
            push(&sp,CtoI(pol[i]));
        }
        // pol[i]が演算子の場合
        else{
            if(pol[i] == '+'){
                second = pop(&sp);
                first = pop(&sp);
                push(&sp,first + second);
            }
            else if(pol[i] == '-'){
                second = pop(&sp);
                first = pop(&sp);
                push(&sp,first - second);
            }
            else if(pol[i] == '*'){
                second = pop(&sp);
                first = pop(&sp);
                push(&sp,first * second);
            }
            else if(pol[i] == '/'){
                second = pop(&sp);
                first = pop(&sp);
                if(second == 0){
                    printf("cannot divine by zero\n");
                }
                else{
                    push(&sp,first / second);
                }
            }
        }
    }

    return pop(&sp); //結果を返す
}

//char型からint型に変換する関数
int CtoI(char c)
{
    //char → int は'0'を引けばいい
    return c - '0';
}


//スタックにpushする関数
void push(int* sp,int n)
{
    stack[*sp] = n;
    (*sp)++;
}

//スタックからpopする関数
int pop(int* sp)
{
    (*sp)--;
    return stack[*sp];
}