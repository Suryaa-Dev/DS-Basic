#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int top=-1, arr[SIZE];
void push();
void pop();
void show();

int main(){
    int choice;
    while (1)
    {
        printf("Enter your choice number to perform action\n");
        printf("1.Push\n2.Pop\n3.Show\n4.Exit\n");
        printf("Enter here:");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Please Enter Choice Correctly\n\n");
                break;
        }
    }   
}

void push(){
    if(top== SIZE - 1 ){
        printf("Stack Overflowed!!\n\n");
    }else{
        int x;
        printf("Enter your number to add it into the Stack:");
        scanf("%d",&x);
        printf("\n");
        top++;
        arr[top]=x;
    }
}

void pop(){
    if(top==-1){
        printf("Stack is Empty\n\n");
    }else{
        printf("The Element popped is: %d\n\n", arr[top]);
        top--;
    }
}

void show(){
    if(top==-1){
        printf("Stack is Empty\n\n");
    }else{
        printf("The elements in stack are:\n");
        for(int i=top;i>=0;i--){
            printf("%d \n", arr[i]);
        }
    }
}