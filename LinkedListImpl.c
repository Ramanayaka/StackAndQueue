#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	int numberOfElements;
	struct Node *nodepointer;

}Stack;

typedef struct queue{
	int numberOfElements;
	struct Node *nodepointer;

}Queue;

typedef struct Node{
	int Number;
	struct Node *preNode;

}node;

Stack* CreateStack(){
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->numberOfElements=0;
	stack->nodepointer =NULL;
return stack;
}

Queue* CreateQueue(){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->numberOfElements=0;
	queue->nodepointer = NULL;
return queue;
}




int StackPush(Stack* stack, int value){
	node* CurrentNode = (node*)malloc(sizeof(node));
	CurrentNode->Number = value;
	CurrentNode->preNode=(stack->nodepointer);
	stack->nodepointer = CurrentNode;
	(stack->numberOfElements)++;
	return 0;
}

int StackPop(Stack* stack, int* value){
	node* CurrentNode;
	if((stack->numberOfElements)<1){
		return -1;
	}else{
		CurrentNode = stack->nodepointer;
		stack->nodepointer = CurrentNode->preNode;
		*value = CurrentNode ->Number;
		free (CurrentNode);

	}

	(stack->numberOfElements)--;
return 0;
}


int StackPeek(const Stack* stack, int* value){
	node* CurrentNode;
	if((stack->numberOfElements)<1){
		return -1;
	}else{
		CurrentNode = stack->nodepointer;
		*value = CurrentNode->Number;
return 0;
}
}

int QueueEnqueue(Queue* queue, int value){
	node* CurrentNode = (node*)malloc(sizeof(node));
	CurrentNode->Number = value;
	CurrentNode->preNode=(queue->nodepointer);
	queue->nodepointer = CurrentNode;
	(queue->numberOfElements)++;
	return 0;
}

int QueueDequeue(Queue* queue, int* value){
	node* CurrentNode;
	node* tempNode;
	int i;
	if((queue->numberOfElements)<1){
		return -1;
	}else{
		CurrentNode = queue->nodepointer;
		for(i=1;i<(queue->numberOfElements);i++){
			CurrentNode= CurrentNode->preNode;
		}
		tempNode=CurrentNode;
		CurrentNode = CurrentNode->preNode;
		*value = tempNode->Number;
		tempNode->preNode = NULL; 
		free(CurrentNode);
		(queue->numberOfElements)--;
	}

return 0;
}

int QueuePeek(const Queue* queue, int* value){
	node* CurrentNode;
	int i;
	CurrentNode = queue->nodepointer;
		for(i=1;i<(queue->numberOfElements);i++){
			CurrentNode= CurrentNode->preNode;
		}
	*value = CurrentNode->Number;

return 0;
}

int DeleteStack(Stack* stack){
	int tmp,i;

	for(i=0;i<stack->numberOfElements;i++){
		StackPop(stack,&tmp);	
	}
	free (stack);
	
return 0;
}
int DeleteQueue(Queue* queue){
	int tmp,i;

	for(i=0;i<queue->numberOfElements;i++){
		QueueDequeue(queue,&tmp);	
	}
	free (queue);


return 0;
}