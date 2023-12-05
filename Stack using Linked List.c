#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int count = 0;

struct stack{
    int items[MAX];
    int top;
};
typedef struct stack st;
 
void createEmptyStack(st *s){
    s->top =-1;
}

int isFull(st *s){
    if(s->top == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(st *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(st *s){
    if(isFull(s)){
        printf("Stack is Full\n");
    }else{
        int newItem;
        printf("Enter your new Item\n");
        scanf("%d", &newItem);
        s->top++;
        s->items[s->top] =newItem;
    }
    count++;
}

void pop(st* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }else{
        printf("Popped item: %d \n", s->items[s->top]);
        s->top--;
    }
    count--;
}

void printStack(st *s){
    printf("Stack: ");
    for(int i=0; i< count; i++){
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main(){
    int ch;
    st *s= (st *)malloc(sizeof(st));
    createEmptyStack(s);

    while(1){
        printf("Choose the following operations\n");
        printf("1.Push \n2.Pop\n3.Show\n4.End\n");
        printf("Enter your choice here:");
        scanf("%d",&ch);

        switch (ch){
            case 1:
                push(s);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printStack(s);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter the valid choice\n");
                break;
        }
    }
}