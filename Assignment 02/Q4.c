#include <stdio.h>

void push(int stack[], int *top, int maxSize){
    int value;
	if(*top == maxSize - 1){
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &value);
    (*top)++;
    stack[*top] = value;
    printf("%d pushed to stack.\n", value);
}

void pop(int stack[], int *top) {
    if(*top == -1){
        printf("Stack Empty!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element is : %d\n", stack[top]);
}

void display(int stack[], int top) {
    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements [Top to Bottom] : ");
    for (int i = top; i >= 0; i--) {
        printf("|%d| ", stack[i]);
    }
    printf("\n");
}

int main(){
    int stack[100];
    int top = -1;
    int maxSize = 100;
    int input;

    do{
        printf("\nEnter \"1\" to Push\n");
        printf("Enter \"2\" to Pop\n");
        printf("Enter \"3\" to Peek\n");
        printf("Enter \"4\" to Display Stack\n");
        printf("Enter \"5\" to Exit\n");
        printf("Input : ");
        scanf("%d", &input);
        switch (input){
            case 1:
                push(stack, &top, maxSize);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                break;
            default:
                printf("INVALID INPUT!\n");
        }
    } while (input != 5);
    return 0;
}

