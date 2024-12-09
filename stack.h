#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#define LIMIT 32768

typedef struct {
    double x;
    double y;
} Point;

typedef struct
{
	Point array[LIMIT];
	int top;
} Stack;

// Helper function to return an invalid value for when stack operation fails
Point ReturnInvalid();

// Function to determine if stack is full
int IsFull(Stack *S);

// Function to determine if stack is empty
int IsEmpty(Stack *S);

// Function to create stack
void Create(Stack *S);

// Function to insert value into top of stack
void Push(Stack *S, Point x, int *status);

// Function to delete top value from stack and return the popped value
Point Pop(Stack *S, int *status);

// Returns the top value in stack
Point Top(Stack *S, int *status);

// Returns the value under the top value in stack
Point NextToTop(Stack *S, int *status);

// Utility function to print the contents of stack
void printstack(Stack S, int size);

#endif // STACK_H