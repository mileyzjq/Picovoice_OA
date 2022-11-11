#include <stdio.h>
#include <stdlib.h>
 
// stack data structure 
struct stack
{
    int maxsize;    // define max capacity of the stack
    int top;
    int *items;
};
 
// initialize the stack
struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);
 
    return pt;
}
 
// return the size of the stack
int size(struct stack *pt) {
    return pt->top + 1;
}
 
// check if the stack is empty or not
int isEmpty(struct stack *pt) {
    return pt->top == -1;                   // or return size(pt) == 0;
}
 
 // check if the stack is full or not
int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;      // or return size(pt) == pt->maxsize;
}
 
// add an element `x` to the stack
void push(struct stack *pt, int x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull(pt))
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Inserting %d\n", x);
 
    // add an element and increment the top's index
    pt->items[++pt->top] = x;
}

// return the top element of the stack
int peek(struct stack *pt)
{
    // check for an empty stack
    if (!isEmpty(pt)) {
        return pt->items[pt->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// pop a top element from the stack
int pop(struct stack *pt)
{
    // check for stack underflow
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Removing %d\n", peek(pt));
 
    // decrement stack size by 1 and (optionally) return the popped element
    return pt->items[pt->top--];
}
 
int main() {
    // create a stack of capacity 20
    struct stack *pt = newStack(20);
 
    push(pt, 1);
    push(pt, 2);
    push(pt, 3);
 
    printf("The top element is %d\n", peek(pt));
    printf("The stack size is %d\n", size(pt));
 
    pop(pt);
    pop(pt);
    pop(pt);
 
    if (isEmpty(pt)) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}
