#include "stack.h"

Point ReturnInvalid()
{
	Point invalid;
	invalid.x = 999999;
	invalid.y = 999999;
	return invalid;
}

int IsFull(Stack *S)
{
	if(S->top >= LIMIT - 1)
		return 1;
	else 
		return 0;
}

int IsEmpty(Stack *S)
{
	if(S->top == -1)
		return 1;
	else 
		return 0;
}

void Create(Stack *S)
{
	S->top = -1;
}

void Push(Stack *S, Point x, int *status)
{
	if(!IsFull(S))
	{
		S->array[++(S->top)] = x;
		*status = 1;
	}
	else
	{
		printf("Stack Overflow\n");
		*status = 0;
	}	
}

Point Pop(Stack *S, int *status)
{
	if(!IsEmpty(S))
	{
		*status = 1;
		return S->array[(S->top)--];
	}
	else
	{
		printf("Stack is Empty\n");
		*status = 0;
		return ReturnInvalid();
	}
}

Point Top(Stack *S, int *status)
{
	if(!IsEmpty(S))
	{
		*status = 1;
		return S->array[S->top];
	}
	else
	{
		printf("Stack is Empty\n");
		*status = 0;
		return ReturnInvalid();
	}
}

Point NextToTop(Stack *S, int *status)
{
	int next;
	if(!IsEmpty(S))
	{
		next = S->top - 1;
		if(next < 0)
		{
			printf("No value next to top\n");
			*status = 0;
			return ReturnInvalid();
		}
		else
		{
			*status = 1;
			return S->array[next];
		}
	}
	else
	{
		printf("Stack is Empty\n");
		*status = 0;
		return ReturnInvalid();
	}
}

void printstack(Stack S, int size)
{
	int i;
	printf("%d\n", (S.top)+1);
	for(i = 0; i <= S.top; i++)
		printf("%lf	%lf\n", S.array[i].x, S.array[i].y);
	printf("\n");
}
