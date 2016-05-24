/*
Create by Hasindu Ramanayaka
E/13/277
CO222 project 2

*/

#include <stdio.h>
#include <stdlib.h>
#define NO_OF_ELEMENTS 100000
typedef struct stack{
	int ElementCountStack;
	int number[NO_OF_ELEMENTS];
}Stack;

typedef struct queue{
	int ElementCountQueue;
	int number[NO_OF_ELEMENTS];
}Queue;

Stack* CreateStack(){
	Stack* stack = (Stack*)malloc (sizeof(Stack));
	stack->ElementCountStack= 0;

return stack;
}

int DeleteStack(Stack* stack){
	free (stack);
return 0;
}

Queue* CreateQueue(){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->ElementCountQueue = 0;
return queue;
}

int DeleteQueue(Queue* queue){
	free (queue);

return 0;
}

int StackPush(Stack* stack, int value){
	stack->number[stack->ElementCountStack]= value;
	stack->ElementCountStack=stack->ElementCountStack+1;

return 0;
}

int StackPop(Stack* stack, int* value){
	*value = stack->number[stack->ElementCountStack-1];
	stack ->ElementCountStack= stack->ElementCountStack-1;

return 0;
}


int StackPeek(const Stack* stack, int* value){
	*value = stack->number[stack->ElementCountStack-1];
return 0;
}

int QueueEnqueue(Queue* queue, int value){
	queue->number[queue->ElementCountQueue]= value;
	queue->ElementCountQueue=queue->ElementCountQueue+1;

return 0;
}

int QueueDequeue(Queue* queue, int* value){
	 *value = queue->number[0];
	 int i = 0;
	 while (i<(queue->ElementCountQueue-1)){
	 	queue->number[i]=queue->number[i+1];
	 	i++;
	 }
	 queue->ElementCountQueue--;
return 0;
}
int QueuePeek(const Queue* queue, int* value){
	*value = queue->number[0];
return 0;
}
