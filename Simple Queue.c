#include<stdlib.h>
#include<stdio.h>
#define SIZE 100

void enqueue();
void dequeue();
void show();

int arr[SIZE], rear= -1, front= -1;

int main(){
    int choice;
    while(1){
        printf("1. Enqueue(Insert)\n");
        printf("2. Dequeue(Delete)\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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

void enqueue(){
    int insert_item;
    if(rear==SIZE-1){
        printf("Overflow!\n\n");
    }else{
        if(front==-1){
            front=0;
        }
        printf("Enter the element: ");
        scanf("%d", &insert_item);
        printf("\n");
        rear=rear+1;
        arr[rear]=insert_item;
    }
}

void dequeue(){
    if(front==-1||front>rear){
        printf("Underflow!\n\n");
        return;
    }else{
        printf("Element deleted is: %d\n", arr[front]);
        front= front+1;
    }
}

void show(){
    if(front==-1){
        printf("Empty Queue!\n\n");
        return;
    }else{
        printf("Queue: \n");
        for(int i=front;i<=rear;i++){
            printf("%d", arr[i]);
            printf("\n");
        }
    }
}